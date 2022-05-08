#include <iostream>
#include <string>
#include <algorithm>

template<typename T>
int reduce(T ar[], int n)
{
    std::sort(ar, ar + n);
    auto an = std::unique(ar, ar + n);
    return an - ar;
}

int main()
{
    long ar_main[19] = { 1,2,3,4,5,6,7,8,9,9,8,7,6,5,4,3,2,1,0 };
    std::string ar_strng[19] = { "a", "b", "c", "d", "e", "f", "g", "h", "a", "b", "c", "d", "a", "f", "g", "h", "i", "j", "k" };
    std::cout << reduce(ar_main, 19) << std::endl;
    std::cout << reduce(ar_strng, 19) << std::endl;
    return 0;
}

