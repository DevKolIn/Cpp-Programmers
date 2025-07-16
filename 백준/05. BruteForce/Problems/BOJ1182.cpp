#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int N, S;
int answer;
std::vector<int> arr;

void combination(int sum, int level)
{
    if (level == N)
    {
        if (sum == S)
            answer++;

        return;
    }

    combination(sum + arr[level], level + 1);
    combination(sum, level + 1);
}

int main()
{
    std::string inputStr;   
    std::getline(std::cin, inputStr);
    {
        std::istringstream iss(inputStr);
        iss >> N >> S;
    }

    std::getline(std::cin, inputStr);
    {
        std::istringstream iss(inputStr);
        int num;
        while (iss >> num)
            arr.push_back(num);
    }

    combination(0, 0);

    if (S == 0)
        answer--;

    std::cout << answer;
}