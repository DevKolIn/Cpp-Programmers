#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> arr = {1,2,3};
    do
    {
        for (int num : arr) {
            std::cout << num << ' ';
        }
        std::cout << '\n';
    } while (std::next_permutation(arr.begin(), arr.end()));

    return 0;
}