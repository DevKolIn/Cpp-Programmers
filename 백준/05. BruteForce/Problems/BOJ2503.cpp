#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

std::vector<int> arr = {1,2,3,4,5,6,7,8,9};
std::vector<bool> isExist(9, false);
struct Answer
{
    int nums = 0;
    int s_count = 0;
    int b_count = 0;
};

bool IsPossibleNum(const std::vector<Answer>& Answers, const std::vector<int>& arr)
{
    int MatchCount = 0;

    for (const Answer& answer : Answers)
    {
        int s_count = 0;
        int b_count = 0;

        int nums = answer.nums;
        for (auto it = arr.rbegin(); it < arr.rend(); ++it)
        {
            int num = nums % 10;
            nums /= 10;

            if (*it == num)
            {
                s_count++;
                continue;
            }

            if (std::find(arr.begin(), arr.end(), num) != arr.end())
            {
                b_count++;
                continue;
            }
        }

        if (s_count == answer.s_count && b_count == answer.b_count)
            MatchCount++;
    }

    return Answers.size() == MatchCount;
}

void permutation(std::vector<std::vector<int>>& permutationArr, std::vector<int>& vec, int index, int level)
{   
    if (vec.size() == 3)
    {
        permutationArr.push_back(vec);
        return;
    }

    for (int i = 0; i < arr.size(); ++i)
    {
        if (isExist[i] == true)
            continue;

        vec.push_back(arr[i]);
        isExist[i] = true;

        permutation(permutationArr, vec, i + 1, level + 1);

        vec.pop_back();
        isExist[i] = false;
    }
}

int main()
{
    int N;
    std::cin >> N;

    std::string bufferflush;
    std::getline(std::cin, bufferflush);

    std::vector<Answer> Answers(N);

    for (int i = 0; i < N; ++i)
    {
        std::string inputStr;
        std::getline(std::cin, inputStr);

        std::istringstream iss(inputStr);
        {
            iss >> Answers[i].nums;
            iss >> Answers[i].s_count;
            iss >> Answers[i].b_count;
        }
    }
   
    std::vector<std::vector<int>> permutationArr;
    std::vector<int> vec;
    permutation(permutationArr, vec, 0, 0);

    int PossibleNumCount = 0;
    for (const std::vector<int>& permutation : permutationArr)
    {
        if(IsPossibleNum(Answers, permutation))
            PossibleNumCount++;
    }

    std::cout << PossibleNumCount;
}