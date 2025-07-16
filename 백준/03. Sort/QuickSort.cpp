#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> arr = {5,4,3,2,1};

    std::sort(arr.begin(), arr.end());

    for (int num : arr)
    {
        std::cout << num << " "; 
    }

    std::cout << '\n';
}