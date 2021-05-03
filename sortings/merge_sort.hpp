#include "includes.hpp"

/**
 * -DESCRIPTION-
 * Merge sort is stable, comparison-based, "divide and conqure"
 * Most implementations produce a stable sort, 
 * which means that the order of equal elements is the same in the input and output.
 * 
 * Demands O(n) extra space and has O(N log N ) stable time complexity
 * 
 * Credits to John von Neuman
**/

/**
 * -UTILTIES-
 * std::inplace_merge -> combines previously two recursively sorted segments 
**/

/**
 * @brief merge sort template function
 * @param first: Bidirectional iterator pointing to first element of interval
 * @param last:  Bidirectional iterator pointing to the last element
 * @param cmp: (optional) functor for comparing elements(std::less<> by default)
 * @return void
**/

namespace utils
{
	    template<typename RandAccIt, typename Compare = std::less<>>
	void merge(RandAccIt left, RandAccIt end_left, RandAccIt right, 
                RandAccIt end_right, RandAccIt out, Compare cmp = Compare{}) 
    {
		while (left != end_left && right != end_right) {
			if (*left < *right) {
				*out++ = *left++;
			}
			else {
				*out++ = *right++;
			}
		}

		while (left != end_left) {
			*out++ = *left++;
		}

		while (right != end_right) {
			*out++ = *right++;
		}
	}
}

namespace sortings 
{
	template<typename RandAccIt>
	void merge_sort(RandAccIt first, RandAccIt last) 
    {
		if (last - first > 1) {
			typedef typename std::iterator_traits<RandAccIt>::value_type value_type;

			RandAccIt middle = first + (last - first) / 2;
			std::vector<value_type> left_table(first, middle);
			std::vector<value_type> right_table(middle, last);

			sortings::merge_sort(left_table.begin(), left_table.end());
			sortings::merge_sort(right_table.begin(), right_table.end());


			utils::merge(left_table.begin(), left_table.end(),
				right_table.begin(), right_table.end(),
				first);
		}
	}
}