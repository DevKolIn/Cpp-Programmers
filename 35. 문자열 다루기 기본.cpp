#include <string>

using namespace std;

bool solution(string s) {
    int len = s.size();
    
    if (len != 4 && len != 6)
        return false;
    
    for (char& ch : s)
    {
         if (isdigit(ch) == false)
             return false;
    }

    return true;
}