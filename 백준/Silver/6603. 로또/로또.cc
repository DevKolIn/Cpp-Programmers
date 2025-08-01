#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

const int lotteryRange = 6;
std::vector<int> arr;

void combination(std::vector<int>& selectedNums, int index)
{
    if (selectedNums.size() == lotteryRange)
    {
        for (int num : selectedNums)
        {
            std::cout << num << " ";
        }
        std::cout << "\n";
        
        return;
    }

    for (int i = index; i < arr.size(); ++i)
    {
        selectedNums.push_back(arr[i]);
        combination(selectedNums, i + 1);
        selectedNums.pop_back();
    }
}

int main()
{
    while (true)
    {
        int k;
        std::cin >> k;

        if (k == 0)
            break;
        
        arr.resize(k);
        for (int i = 0; i < k; ++i)
            std::cin >> arr[i];

        std::sort(arr.begin(), arr.end());

        std::vector<int> selectedNums;
        combination(selectedNums, 0);
        std::cout << std::endl;
    }
    
    return 0;
}