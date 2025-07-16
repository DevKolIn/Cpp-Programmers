#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N;
    std::cin >> N;

    std::vector<int> arr;
    for (int i = 1; i <= N; ++i)
    {
        arr.push_back(i);
    }

    do
    {
        for (int num : arr)
        {
            std::cout << num <<" ";
        }
        std::cout << '\n';
    } while (std::next_permutation(arr.begin(), arr.end()));

    return 0;
}