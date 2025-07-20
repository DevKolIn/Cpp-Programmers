#include <iostream>
#include <set>
#include <vector>

int main()
{
    int N, M;

    std::cin >> N;
    std::set<int> nums;
    for (int i = 0; i < N; ++i)
    {
        int num;
        std::cin >> num;

        nums.insert(num);
    }

    std::cin >> M;
    std::vector<int> searchNums(M);
    for (int i = 0; i < M; ++i)
        std::cin >> searchNums[i];

    for (int i = 0; i < M; ++i)
    {
        std::cout << nums.count(searchNums[i]) << '\n';
    } 
}