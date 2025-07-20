#include <iostream>
#include <vector>

int main()
{
    int N;
    std::cin >> N;

    std::vector<int> dp(31, 0);
    dp[0] = 1;

    for (int i = 2; i <= N; ++i)
    {
        dp[i] = (dp[i - 2] * 3);
        for (int j = i - 4; j >= 0; j -=2)
        {
            dp[i] += dp[j] * 2;
        }
    }

    std::cout << dp[N];
}