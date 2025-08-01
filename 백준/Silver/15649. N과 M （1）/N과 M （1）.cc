#include <iostream>
#include <vector>

int N, M;
std::vector<bool> visited;
std::vector<int> result;

void dfs(int depth)
{
    if (depth == M)
    {
        for (int num : result)
            std::cout << num << ' ';
        std::cout << '\n';
        return;
    }

    for (int i = 1; i <= N; ++i)
    {
        if (visited[i])
            continue;

        visited[i] = true;
        result.push_back(i);
        dfs(depth + 1);
        result.pop_back();
        visited[i] = false;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M;

    visited.resize(N + 1, false);
    dfs(0);
    return 0;
}