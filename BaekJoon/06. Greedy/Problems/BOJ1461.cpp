#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A,B;
    for (int i = 0; i < N; ++i)
    {
        int num;
        std::cin >> num;

        if (num >= 0)
            A.push_back(num);
        else
            B.push_back(-num);
    }

    std::sort(A.begin(), A.end(), std::greater<int>());
    std::sort(B.begin(), B.end(), std::greater<int>());

    int answer = 0;
    for (int i = 0; i < A.size(); i += M)
    {
        answer += A[i];
    }
    for (int i = 0; i < B.size(); i += M)
    {
        answer += B[i];
    }
    
    answer *= 2;

    int BigNumber = 0;
    if (A.size() >= 1)
    {
        BigNumber = A[0];
    }
    if (B.size() >= 1)
    {
        BigNumber = std::max(BigNumber, B[0]);
    }

    answer -= BigNumber;
    std::cout << answer;
}