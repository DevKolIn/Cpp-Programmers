#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::string inputStr;
    std::cin >> inputStr;

    std::sort(inputStr.begin(), inputStr.end());
    
    int answer = 0;
    do
    {
        answer += 1;

        for (int i = 1; i < inputStr.size(); ++i)
        {
            char prevChar = inputStr[i - 1];
            char currentChar = inputStr[i];
            
            if (prevChar == currentChar)
            {
                answer -= 1;
                break;
            }
        }
    } while (std::next_permutation(inputStr.begin(), inputStr.end()));

    std::cout << answer;
}