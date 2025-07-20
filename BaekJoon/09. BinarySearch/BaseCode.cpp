#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& arr, int target)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] <= target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main()
{
    const int N = 20;
    std::vector<int> arr(N);
    for (int i = 0; i < N; ++i)
    {
        arr[i] = i + 1;
    }
    
    std::cout << binarySearch(arr, 5);
}