#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int result = 0;
    for (int idx = 0; idx < absolutes.size(); idx++)
    {
        int sign = signs[idx] ? 1 : -1;
        result += absolutes[idx] * sign;
    }
    
    return result;
}