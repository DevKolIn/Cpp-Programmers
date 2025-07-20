#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

int lotteryRange = 6;
std::vector<int> selectNums;

void combination(std::vector<int>& arr, int index, int level)
{
    if (arr.size() == lotteryRange)
    {
        for (int num : arr)
        {
            std::cout << num << ' ';
        }
        std::cout << '\n';
        return;
    }

    for (int i = index; i < selectNums.size(); ++i)
    {
        arr.push_back(selectNums[i]);
        combination(arr, i + 1, level + 1);
        arr.pop_back();
    }
}

int main()
{
    while(true)
    {
        std::string inputStr;
        std::getline(std::cin, inputStr);
        
        if (inputStr == "0")
            break;
        
        selectNums.clear();

        std::istringstream iss(inputStr);
        {
            int num;
            iss >> num;
            while (iss >> num)
            {
                selectNums.push_back(num);
            }
        }
        
        std::vector<int> arr;
        combination(arr, 0, 0);
        std::cout << '\n';
    }

    return 0;
}