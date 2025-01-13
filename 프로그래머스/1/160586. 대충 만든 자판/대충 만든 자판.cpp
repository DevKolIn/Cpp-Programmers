#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool minCompare(int a, int b) {
    if (b < 0) return true;
    return a < b; 
}

int getAlphabetIdx(char ch)
{
    return ch - 'A';
}

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    vector<int> alphabetsDistance(26, -1);
    
    for (string str :keymap)
    {
        for (int idx = 0; idx < str.size(); idx++)
        {
            char alphabetIdx = getAlphabetIdx(str[idx]);
       alphabetsDistance[alphabetIdx] = min(alphabetsDistance[alphabetIdx], idx + 1, minCompare);
        }
    }
    

    for (string target : targets)
    {
        int targetTotal = 0;
        for (char ch : target)
        {
            char alphabetIdx = getAlphabetIdx(ch);
            if (alphabetsDistance[alphabetIdx] == -1)
            {
                targetTotal = -1;
                break;
            }
            else
            {
                targetTotal += alphabetsDistance[alphabetIdx];
            }
        }
        answer.push_back(targetTotal);
    }
    
    return answer;
}