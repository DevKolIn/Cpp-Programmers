#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

int L;
int C;
std::string alphabets;

bool isValid(const std::string& str)
{
    int vowelCount = 0;
    int consonantCount = 0;

    for (char ch : str)
    {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            vowelCount++;
        else
            consonantCount++;

        if (vowelCount >= 1 && consonantCount >= 2)
            return true;
    }

    return false;
}

void combination(std::string& str, int index, int level)
{
    if (str.size() == L)
    {
        if (isValid(str))
        {
            for (char num : str)
            {
                std::cout << num;
            }
            std::cout << '\n';
        }
        
        return;
    }

    for (int i = index; i < alphabets.size(); ++i)
    {
        str += alphabets[i];
        combination(str, i + 1, level + 1);
        str.pop_back();
    }
}

int main()
{
    std::string inputStr;
    std::getline(std::cin, inputStr);
    {
        std::istringstream iss(inputStr);
        iss >> L;
        iss >> C;
    }

    std::getline(std::cin, inputStr);
    {
        std::istringstream iss(inputStr);
        char ch;
        while (iss >> ch)
            alphabets += ch;
    }

    std::sort(alphabets.begin(), alphabets.end());

    std::string str;
    combination(str, 0, 0);
}