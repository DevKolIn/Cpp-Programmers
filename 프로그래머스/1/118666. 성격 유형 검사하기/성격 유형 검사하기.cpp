#include <string>
#include <vector>
#include <utility>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    char personalityType[26] = {0,};
    
    string answer = "";
    for (int idx = 0; idx < choices.size(); ++idx)
    {
        char typeAIdx = survey[idx][0] - 'A';
        char typeBIdx = survey[idx][1] - 'A';
        int choice = choices[idx];
        
        if (choice < 4) 
        {
            personalityType[typeAIdx] += 4 - choice;
        }
        if (choice > 4)
        {
            personalityType[typeBIdx] += choice - 4;
        }
    }
    vector<pair<char, char>> pairs =
    {
        {'R','T'},
        {'C','F'},
        {'J','M'},
        {'A','N'},
    };
    
    for (pair<char, char> pair : pairs)
    {
        if (personalityType[pair.first - 'A'] >= personalityType[pair.second - 'A'])
        {
            answer += pair.first;
        }
        else
        {
            answer += pair.second;
        }
    }
    
    return answer;
}