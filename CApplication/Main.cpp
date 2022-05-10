#include <iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<ctime>

std::vector<int> Lotto(int loto_n, int loto_s);

int main()
{
    std::srand(time(0));
    std::vector<int> winners;
    winners = Lotto(51, 6);
    for (auto var : winners)
        std::cout << var << "\n";
    return 0;
}

std::vector<int> Lotto(int loto_n, int loto_s)
{
    std::vector<int> collector;
    for (int i = 1; i <= loto_n; ++i)
        collector.push_back(i);
    std::random_shuffle(collector.begin(), collector.end());
    collector.resize(loto_s);
    return collector;
}
