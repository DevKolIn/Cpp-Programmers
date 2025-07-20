#include <iostream>
#include <vector>
#include <algorithm>

int binarySearch(const std::vector<int>& arr, int target)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] < target)
            left = mid + 1;

        if (arr[mid] > target)
            right = mid - 1;

        if (arr[mid] == target)
            return 1;
    }

    return 0;
}

int main()
{
    int N, M;

    std::cin >> N;
    std::vector<int> nums(N);
    for (int i = 0; i < N; ++i)
        std::cin >> nums[i];

    std::sort(nums.begin(), nums.end());

    std::cin >> M;
    std::vector<int> searchNums(M);
    for (int i = 0; i < M; ++i)
        std::cin >> searchNums[i];

    for (int searchNum : searchNums)
    {
        std::cout << binarySearch(nums, searchNum) << '\n'; 
    }
}