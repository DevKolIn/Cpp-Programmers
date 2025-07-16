#include <iostream>
#include <vector>
#include <algorithm>

bool Compare(int a, int b)
{
    // False아면, a,b가 교환된다.
    return a > b;
}

int main()
{
    std::vector<int> arr = {1,2,3,4,5};

    std::sort(arr.begin(), arr.end(), Compare);

    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";
}