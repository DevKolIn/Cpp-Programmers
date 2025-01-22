#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
    bool IsFirst = true;
    
    for (char& ch : s)
    {
        if (isalpha(ch))
        {
            if (IsFirst)
            {
                IsFirst = false;
                ch = toupper(ch);
            }
            else
            {
                ch = tolower(ch);
            }
        }
        else
        {
            IsFirst = false;
        }
        
        if (ch == ' ')
            IsFirst = true;
    }
    
    return s;
}