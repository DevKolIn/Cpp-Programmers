#include <string>
#include <cctype>

using namespace std;

string solution(string s) {
    bool flag = true;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            flag = true;
            continue;
        }
        
        if (flag)
        {
            s[i] = toupper(s[i]);
        }
        else
        {
            s[i] = tolower(s[i]);
        }
        
        flag ^= true;
    }
    
    return s;
}