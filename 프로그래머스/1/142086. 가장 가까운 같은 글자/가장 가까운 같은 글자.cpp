#include <string>
#include <vector>

using namespace std;

int alphaPos[26];

vector<int> solution(string s) {
    vector<int> answer;
    std::fill(std::begin(alphaPos), std::end(alphaPos), -1);
    
    for (int i = 0; i < s.size(); i++)
    {
        int idx = s[i] - 'a';
        
        if (alphaPos[idx] == -1) answer.push_back(-1);
        else answer.push_back(i - alphaPos[idx]);
        
        alphaPos[idx] = i;
    }
    
    return answer;
}