#include <iostream>

template<typename FwdIt>
void printArray(FwdIt begin, FwdIt end)
{
    for (; begin != end; ++begin) {
        std::cout << *begin << '\t';
    };  
    std::cout << std::endl;
}