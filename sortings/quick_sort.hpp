#include "includes.hpp"

namespace utils
{
    template<class ForwardIt, class UnaryPredicate>
    ForwardIt partition(ForwardIt first, ForwardIt last, UnaryPredicate pred)
    {
        first = std::find_if_not(first, last, pred);
        
        if (first == last) 
            return first;
    
        for (ForwardIt i = std::next(first); i != last; ++i) {
            if (pred(*i)) {
                std::iter_swap(i, first);
                ++first;
            }
        }
        return first;
    }
}

namespace sortings
{
    template<class FwdIt, class Compare = std::less<>>
    void quick_sort(FwdIt first, FwdIt last, Compare cmp = Compare{})
    {
        auto const N = std::distance(first, last);
        
        if (N <= 1) 
            return;

        auto const pivot = *std::next(first, N / 2);

        auto const middle1 = utils::partition(first, last, [=](auto const& elem){ 
            return cmp(elem, pivot); 
        });
        auto const middle2 = utils::partition(middle1, last, [=](auto const& elem){ 
            return !cmp(pivot, elem);
        });

        quick_sort(first, middle1, cmp); // assert(std::is_sorted(first, middle1, cmp));
        quick_sort(middle2, last, cmp);  // assert(std::is_sorted(middle2, last, cmp));
    }
}