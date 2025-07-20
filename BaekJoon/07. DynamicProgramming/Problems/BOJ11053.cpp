#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N;
    std::cin >> N;

    std::vector<int> arr(N);
    for (int i = 0; i < N; ++i)
        std::cin >> arr[i];

    std::vector<int> arrLength(1000 + 1, 0);
    for (int num : arr)
    {
        int max = 0;
        for (int i = 1; i < num; ++i)
        {
            max = std::max(max, arrLength[i]);
        }

        arrLength[num] = max + 1;
    }

    std::cout << *std::max_element(arrLength.begin(), arrLength.end());
}