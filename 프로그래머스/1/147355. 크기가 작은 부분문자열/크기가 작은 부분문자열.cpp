#include <string>

using namespace std;

int solution(string t, string p) {
    int result = 0;
    int pSize = p.length();
    long long pNum = stoll(p);

    for (size_t i = 0; i <= t.length() - pSize; i++)
    {
        string subT = t.substr(i, pSize);   
        if (stoll(subT) <= pNum)
            result++;  
    }
     
    return result;
}