#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main()
{
    int N;
    std::cin >> N;
    std::vector<int> arr(N);
    
    for (int i = 0; i < N; ++i)
        std::cin >> arr[i];

    std::vector<int> dp_table(N+1);
    dp_table[0] = 0;

    int answer = INT_MIN;
    for (int i = 1; i <= N; ++i)
    {
        dp_table[i] = std::max(0, dp_table[i - 1]) + arr[i - 1];
        answer = std::max(answer, dp_table[i]);
    }

    std::cout << answer;
}