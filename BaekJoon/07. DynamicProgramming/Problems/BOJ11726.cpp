#include <iostream>
#include <vector>

int main()
{
    int N;
    std::cin >> N;
    std::vector<int> dp(N + 1);

    dp[0] = 1;
    dp[1] = 2;

    for (int i = 2; i < N; ++i)
    {
        dp[i] = dp[i-1] + dp[i-2] % 10007;
    }
    
    std::cout << dp[N - 1];
}