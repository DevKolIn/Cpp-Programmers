#include <string>

using namespace std;

string solution(string s, int n) {
    for (char& ch : s)
    {
        if (ch >= 'a' && ch <= 'z')
        {
            int next = (ch - 'a' + n) % 26;
            ch = 'a' + next;
        }
        if (ch >= 'A' && ch <= 'Z')
        {
            int next = (ch - 'A' + n) % 26;
            ch = 'A' + next;
        }
    }
    
    return s;
}