#include <iostream>
#include <vector>

int N, M;
std::vector<int> arr;
std::vector<int> result;

void dfs(int index)
{
    if (result.size() == M)
    {
        for (int num : result)
            std::cout << num << ' ';
        std::cout << '\n';
        return;
    }

    for (int i = index; i < N; ++i)
    {
        result.push_back(i + 1);
        dfs(i + 1);
        result.pop_back();
    }
}

int main()
{
    std::cin >> N >> M;

    dfs(0);

    return 0;
}