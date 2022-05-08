#include <iostream>
#include <vector>
#include <algorithm>

int reduce(long ar[], int n);

int main()
{
    long ar_main[19] = { 1,2,3,4,5,6,7,8,9,9,8,7,6,5,4,3,2,1,0 };
    std::cout << reduce(ar_main, 19) << std::endl;
    return 0;
}

int reduce(long ar[], int n)
{
    std::sort(ar, ar + n);
    auto an = std::unique(ar, ar + n);
    return an - ar;
}
