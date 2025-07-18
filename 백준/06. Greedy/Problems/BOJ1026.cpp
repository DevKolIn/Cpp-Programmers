#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    std::vector<int> B(N);

    for (int i = 0; i < N; ++i)
    {
        std::cin >> A[i];
    }

    for (int i = 0; i < N; ++i)
    {
        std::cin >> B[i];
    }

    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end(), std::greater<int>());

    int answer = 0;
    for (int i = 0; i < N; ++i)
    {
        answer += A[i] * B[i];
    }

    std::cout << answer << '\n';
}