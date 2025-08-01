#include <iostream>
#include <vector>

int N, M;
std::vector<int> arr;

void dfs()
{
    if (arr.size() == M)
    {
        for (int i = 0; i < M; ++i)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << '\n';
        
        return;
    }
    
    for (int i = 1; i <= N; ++i)
    {
        arr.push_back(i);
        dfs();
        arr.pop_back();
    }
}

int main()
{
    std::cin >> N >> M;
    
    dfs();
    
    return 0;
}