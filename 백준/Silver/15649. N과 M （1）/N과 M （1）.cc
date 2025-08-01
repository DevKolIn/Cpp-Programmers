#include <iostream>
#include <vector>
#include <algorithm>

int N,M;
std::vector<int> v;
std::vector<bool> isExist;

void combination(std::vector<int>& arr, int index)
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

    for (int i = 0; i < v.size(); ++i)
    {
        if (isExist[i])
            continue;

        isExist[i] = true;
        arr.push_back(v[i]);

        combination(arr, i + 1);
        
        isExist[i] = false;
        arr.pop_back();
    }
}

int main()
{
    std::cin >> N >> M;

    v.resize(N);
    isExist.resize(N, false);
    for (int i = 0; i < N; ++i)
    {
        v[i] = i + 1;
    }

    std::vector<int> arr;
    combination(arr, 0);
}