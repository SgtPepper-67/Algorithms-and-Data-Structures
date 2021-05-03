#include "sortings/sortings.hpp"

int main()
{
    std::vector<int64_t> vec1 = {1,3,2,1,4,12,44,12,44,12,33,3000, -1222, 1000000000, -12, 999};
    auto  vec2 = vec1;

    sortings::bubble_sort(vec2.begin(), vec2.end());
    printArray(vec2.begin(), vec2.end());

    vec2 = vec1;
    sortings::selection_sort(vec2.begin(), vec2.end());
    printArray(vec2.begin(), vec2.end());

    vec2 = vec1;
    sortings::shell_sort(vec2.begin(), vec2.end());
    printArray(vec2.begin(), vec2.end());

    vec2 = vec1;
    sortings::insertion_sort(vec2.begin(), vec2.end());
    printArray(vec2.begin(), vec2.end());

    vec2 = vec1;
    sortings::quick_sort(vec2.begin(), vec2.end());
    printArray(vec2.begin(), vec2.end());

    vec2 = vec1;
    sortings::merge_sort(vec2.begin(), vec2.end());
    printArray(vec2.begin(), vec2.end());

    printArray(vec1.begin(), vec1.end());
}