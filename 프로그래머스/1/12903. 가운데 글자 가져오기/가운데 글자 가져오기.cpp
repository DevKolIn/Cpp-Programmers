#include <string>
#include <vector>

using namespace std;

string solution(string str) {
    string result = "";
    int length = str.length();
    int mid = length / 2;
    
    if (length % 2 == 0)
    {
        result += str[mid - 1];
        result += str[mid];
    }
    else
    {
       result += str[mid];
    }
    
    
    return result;
}