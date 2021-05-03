#include "includes.hpp"

namespace utils 
{
    template<class IntegralType>
    IntegralType get_initial_gap(IntegralType range_size)
    {
        IntegralType h = 1;

        while (h < range_size / 3)
        {
            h = (3 * h) + 1;
        }
        return h;
    }

    template<class IntegralType>
    void decrease_gap(IntegralType& gap)
    {
        gap /= 3;
    }
}

namespace sortings 
{
    template<typename RandAccIt, typename Compare = std::less<>>
    void shell_sort(RandAccIt first, RandAccIt last, Compare cmp = Compare{})
    {
        if (first != last)
        {
            auto range_size = std::distance(last,  first);
            auto gap = utils::get_initial_gap(range_size);

            for( gap; gap != 0; utils::decrease_gap(gap))
                for( auto i = first + gap; i != last; ++i )
                    for( auto j = i; j - first >= gap && cmp( *j, *( j - gap ) ); j -= gap )
                        std::swap( *j, *( j - gap ) );
        }
    }
}

