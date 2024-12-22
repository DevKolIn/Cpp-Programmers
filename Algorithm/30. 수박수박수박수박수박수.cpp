#include <string>

using namespace std;

string solution(int n) {
    string result;
    result.reserve(n);
    
    for (int i = 0; i < n; i++)
    {
        result += (i % 2 == 0) ? "수" : "박";
    }
    
    return result;
}