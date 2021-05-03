#include "includes.hpp"

/**
 * -DESCRIPTION-
 * Insertion sort is one of the elementary sorting algorithms with O(N²) worst-case time, 
 * insertion sort is the algorithm of choice either when the data is nearly sorted (because it is adaptive)
 * or when the problem size is small (because it has low overhead). For these reasons,
 * and because it is also stable, insertion sort is often used as the recursive base case 
 * (when the problem size is small) for higher overhead divide-and-conquer sorting algorithms, 
 * such as merge sort or quick sort.
**/

/**
 * -UTILTIES-
 * std::upper_bound -> to find the location where the current element needs to go(binary search by default)
 * std::rotate      -> to shift the remaining elements after insertion
**/

/**
 * Possible optimization:
 * Iterate from std::next(first), because first element 
 * already is in place/
**/

/**
 * @brief insertion sort template function
 * @param first: forward iterator to the beginning of the interval
 * @param last: forward iteratir ti the end of the interval
 * @param cmp: (optional) functor for comparing elements(std::less<> by default)
 * @return void
**/
namespace utils
{
    template<class FwdIt, class T, class Compare = std::less<>>
    FwdIt upper_bound(FwdIt first, FwdIt last, const T& value, Compare cmp = Compare{} )
    {
        FwdIt it;       
        auto count = std::distance(first, last);
        decltype(count) step;

        while (count > 0) {
            it = first; 
            step = count / 2;
            std::advance(it, step);
            
            if (!cmp(value, *it)) {
                first = ++it;
                count -= step + 1;
            } 
            else
                count = step;
        }       
        return first;
    }

    template<class FwdIt>
    FwdIt rotate(FwdIt first, FwdIt n_first, FwdIt last)
    {
        if(first == n_first) 
            return last;
        if(n_first == last) 
            return first;
        
        FwdIt read      = n_first;
        FwdIt write     = first;
        FwdIt next_read = first; // read position for when "read" hits "last"
        
        while(read != last) {
            if(write == next_read) 
                next_read = read; // track where "first" went

            std::iter_swap(write++, read++);
        }
        
        // rotate the remaining sequence into place
        (rotate)(write, next_read, last);
        return write;
    }

}



namespace sortings
{
    template<class FwdIt, class Compare = std::less<>>
    void insertion_sort(FwdIt first, FwdIt last, Compare cmp = Compare{})
    {
        if (std::distance(first, last) <= 1)
            return;

        for (auto it = first; it != last; ++it) {
            auto const insertion = utils::upper_bound(first, it, *it, cmp);
            utils::rotate(insertion, it, std::next(it)); 
            //assert(std::is_sorted(first, std::next(it), cmp));
        }
    }
}