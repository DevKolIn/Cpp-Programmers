#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    map<char, int> map;
    
    string answer = "";
    for (int idx = 0; idx < choices.size(); ++idx)
    {
        char typeAIdx = survey[idx][0];
        char typeBIdx = survey[idx][1];
        int choice = choices[idx];
        
        if (choice < 4) 
        {
            map[typeAIdx] += 4 - choice;
        }
        if (choice > 4)
        {
            map[typeBIdx] += choice - 4;
        }
    }
    
    char personalityTypes[4][2] =
    {
        {'R','T'},
        {'C','F'},
        {'J','M'},
        {'A','N'},
    };
    
    for (int i = 0; i < 4; i++)
    {
        int scoreA = map[personalityTypes[i][0]];
        int scoreB = map[personalityTypes[i][1]];
        
        if (scoreA >= scoreB)
        {
            answer += personalityTypes[i][0];
        }
        else
        {
            answer += personalityTypes[i][1];
        }
    }
    
    return answer;
}