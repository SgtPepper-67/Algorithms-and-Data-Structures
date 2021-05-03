#include "includes.hpp"

/**
 * -DESCRIPTION-
 * Selection sort does not adapt to the data in any way, so its runtime is always O(N²). 
 * However, selection sort has the property of minimizing the number of swaps. 
 * In applications where the cost of swapping items is high, 
 * selection sort very well may be the algorithm of choice.
 * 
 * Notice that random access iterators aren't required.
 * 
**/

/**
 *  * UTILTIES *
 * std::min_element -> to find the remaining minimum element during iterations
 * std::iter_swap   -> to swap current with remaing minimum
 * NOTE:(implementation with std::swap(*it1, *it2) could fit in for almost all compillers)
**/ 

/** 
 * @brief selection sort template function
 * @param first: forward iterarator to the begin of the interval
 * @param last: forward iteratir ti the end of the interval
 * @param cmp: (optional) functor for comparing elements(std::less<> by default)
 * @return void
**/

namespace utils
{
    template<class ForwardIt, class Compare = std::less<>>
    ForwardIt min_element(ForwardIt first, ForwardIt last, Compare cmp = Compare{})
    {
        if (first == last) return last;
    
        ForwardIt smallest = first++;
        
        for (; first != last; ++first) {
            if (cmp(*first, *smallest)) {
                smallest = first;
            }
        }
        return smallest;
    }
}



namespace sortings 
{
    template<class FwdIt, class Compare = std::less<>>
    void selection_sort(FwdIt first, FwdIt last, Compare cmp = Compare{})
    {
        if (std::distance(first, last) <= 1)
            return;

        for (auto it = first; it != last; ++it) {
            auto const selection = std::min_element(it, last, cmp);
            std::iter_swap(selection, it); 
            // assert(std::is_sorted(first, std::next(it), cmp));
        }
    }
}