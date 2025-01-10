#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    for (int idx = 0; idx < s.size();)
    {
        char curAlpha = s[idx];
        int curAlphaCount = 0;
        int otherAlphaCount = 0;
        
        int nextIdx = idx;
        while (nextIdx < s.size())
        {
            if (curAlpha == s[nextIdx])
            {
                ++curAlphaCount;
            }
            else
            {
                ++otherAlphaCount;
            }
            
            if (curAlphaCount == otherAlphaCount)
            {
                break;
            }
            nextIdx++;
        }
        idx = nextIdx + 1;
        answer++;
    }
    
    return answer;
}