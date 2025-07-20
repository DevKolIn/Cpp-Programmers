#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> arr = {1,2,3,4,5};

    std::sort(arr.begin(), arr.end(), std::greater<int>());

    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";
}