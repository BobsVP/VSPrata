#include<iostream>
#include<ctime>
#include<vector>
#include<list>
#include<algorithm>
#include<cstdlib>

void generate_rand(int& t);

int main()
{
    srand(time(NULL));
    std::vector<int> vi0(10000000);
    std::for_each(vi0.begin(), vi0.end(), generate_rand);
    std::vector<int> vi(vi0);
    std::list<int> li(vi0.begin(), vi0.end());
    clock_t start = clock();
    std::sort(vi.begin(), vi.end());
    clock_t end = clock();
    std::cout << (double)(end - start) / CLOCKS_PER_SEC << std::endl;
    start = clock();
    li.sort();
    end = clock();
    std::cout << (double)(end - start) / CLOCKS_PER_SEC << std::endl;
    li.clear();
    std::copy(vi0.begin(), vi0.end(), std::back_inserter(li));
    start = clock();
    std::copy(li.begin(), li.end(), vi.begin());
    std::sort(vi.begin(), vi.end());
    li.clear();
    std::copy(vi.begin(), vi.end(), std::back_inserter(li));
    end = clock();
    std::cout << (double)(end - start) / CLOCKS_PER_SEC << std::endl;
    return 0;
}

void generate_rand(int& t)
{
    t = rand();
}
