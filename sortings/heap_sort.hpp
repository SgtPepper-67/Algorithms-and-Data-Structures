#include "includes.hpp"

namespace utils
{
    template<typename FwdIt, typename Compare = std::less<>>
    void sink(FwdIt begin, FwdIt end, std::size_t index, Compare cmp = Compare{})
    {
        auto size = std::distance(begin, end);
        auto current = index;
        std::size_t child;

        while ((child = 2 * current + 1) < size)
        {
            auto itr_child   = begin + child;
            auto itr_current = begin + current;

            if ( (child < size - 1) 
                && cmp(*itr_child, *(itr_child + 1)) )
            {
                ++itr_child;
            }

            if (!cmp(*itr_current, *itr_child))
            {
                break;
            }
            std::swap(*itr_current, *itr_child);
            current = child;
        }
    }
}

namespace sortings
{
    template<typename BiDirIt, typename Compare = std::less<>>
    void heap_sort(BiDirIt begin, BiDirIt end, Compare cmp = Compare{})
    {
        std::size_t size = std::distance(begin, end);
        for (int i = size / 2 - 1; i > -1; --i) 
        {
            utils::sink(begin, end, i, cmp);    
        }
        while (begin != --end) 
        {
            std::swap(*begin, *end);
            utils::sink(begin, end, 0, cmp);
        }
    }
}