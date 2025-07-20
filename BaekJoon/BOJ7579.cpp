#include <iostream>
#include <vector>
#include <numeric>

int main()
{
    int N, M;
    std::cin >> N >> M;

    std::vector<int> arr(N);
    for (int i = 0; i < N; ++i)
        std::cin >> arr[i];

    std::vector<int> costs(N);
    for (int i = 0; i < N; ++i)
        std::cin >> costs[i];

    int totalCost = std::accumulate(arr.begin(), arr.end(), 0);
    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(totalCost + 1, 0));

    for (int n = 1; n <= N; ++n)
    {
        for (int c = 0; c < totalCost; ++c)
        {
            dp[n][c] = dp[n - 1][c];
            if (c - costs[n - 1] >= 0)
            {
                dp[n][c] = std::max(dp[n][c], dp[n][c - costs[n - 1]] + arr[n - 1]);
            }
        }
    }

    for (int i = 0; i < totalCost; ++i)
    {
        if (dp[N][i] >= M)
        {
            std::cout << i << std::endl;
            break;
        }
    }
}