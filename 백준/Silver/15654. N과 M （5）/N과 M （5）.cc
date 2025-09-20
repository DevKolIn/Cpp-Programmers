#include <iostream>
#include <vector>
#include <algorithm>

int N, M;
std::vector<int> nums;
std::vector<int> v;
std::vector<bool> visited;

void dfs(int depth)
{
    if (v.size() == M)
    {
        for (int i = 0; i < M; ++i)
            std::cout << v[i] << " ";
        std::cout << '\n';

        return;
    }

    for (int i = 0; i < N; ++i)
    {
        if (visited[i])
            continue;

        visited[i] = true;
        v.push_back(nums[i]);
        dfs(depth + 1);
        v.pop_back();
        visited[i] = false;
    }
}

int main()
{
    std::cin >> N >> M;
    nums.resize(N);
    visited.resize(N, false);
    
    for (int i = 0; i < nums.size(); ++i)
        std::cin >> nums[i];

    std::sort(nums.begin(), nums.end());
    dfs(0);
    
    return 0;
}