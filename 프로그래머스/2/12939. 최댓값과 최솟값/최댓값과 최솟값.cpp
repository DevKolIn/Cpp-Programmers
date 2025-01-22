#include <string>
#include <sstream>
#include <climits>

using namespace std;

string solution(string s) {
    int minValue = INT_MAX;
    int maxValue = INT_MIN;
    
    int token;
    stringstream stream(s);
    while (stream >> token)
    {
        if (minValue > token)
            minValue = token;
        if (maxValue < token)
            maxValue = token;
    }
    
    return to_string(minValue) + " " + to_string(maxValue);
}