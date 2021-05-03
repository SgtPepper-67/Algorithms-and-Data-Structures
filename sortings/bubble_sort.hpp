#include "includes.hpp"
#include <cassert>

namespace utils
{
    template<class BiDirIt, class Compare = std::less<> >
    bool bubble_up(BiDirIt first, BiDirIt last, Compare cmp = Compare{})
    {
        bool is_swapped = false;

        for (auto it = first; it != std::prev(last); ++it) {
            if (cmp(*std::next(it), *it)) {
                std::swap(*it, *std::next(it));
                is_swapped = true;
            } 
        }

        return is_swapped;
    }
}

namespace sortings
{
    template<class BiDirIt, class Compare = std::less<>>
    void bubble_sort(BiDirIt first, BiDirIt last, Compare cmp = Compare{})
    {
        bool swapped = true;

        while(swapped) {
            swapped = utils::bubble_up(first, last, cmp);
            last = std::prev(last);
        }
    }
}