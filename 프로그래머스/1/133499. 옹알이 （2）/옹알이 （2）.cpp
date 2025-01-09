#include <string>
#include <map>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    map<char, string> map =
    {
        {'a', "aya"},
        {'y', "ye"},
        {'w', "woo"},
        {'m', "ma"}
    };
    
    for (int i = 0; i < babbling.size(); i++)
    {
        string str = babbling[i];
        int matchedCount = 0;
        char prevCh = 0;
        for (int j = 0; j < str.size(); j++)
        {
            char ch = str[j];
            auto it = map.find(ch);
            if (it != map.end())
            {
                int bablingSize = it->second.size();
                string temp = str.substr(j, bablingSize);
                if (temp == it->second)
                {
                    if (prevCh != it->first)
                    {
                        matchedCount += bablingSize;
                        j += bablingSize - 1;
                        prevCh = it->first;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            else 
            {
                break;
            }
        }
        if (matchedCount == str.size())
            answer++;
    }
    
    return answer;
}