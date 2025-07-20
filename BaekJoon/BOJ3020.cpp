#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main()
{
    int N, H;
    std::cin >> N >> H;
    
    std::vector<int> bots(H + 1, 0);
    std::vector<int> tops(H + 1, 0);

    for (int i = 0; i < N; ++i)
    {
        int num;
        std::cin >> num;

        if (i % 2 == 0)
            bots[num]++;
        else
            tops[H - num + 1]++;
    }

    int count = 0;
    int minDestroyCount = INT_MAX;
    int destroyCount = N / 2;
    for (int h = 1; h <= H; ++h)
    {
        destroyCount -= bots[h - 1];
        destroyCount += tops[h];

        if (minDestroyCount == destroyCount)
        {
            count++;
        }

        if (minDestroyCount > destroyCount)
        {
            minDestroyCount = destroyCount;
            count = 1;
        }
    }

    std::cout << minDestroyCount << " " << count;
}