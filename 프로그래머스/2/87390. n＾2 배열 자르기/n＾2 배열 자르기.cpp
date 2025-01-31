#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    for (long long i = left; i <= right; ++i)
    {
        long long y = (i / n) + 1;
        long long x = (i % n) + 1;
        int value = max(y, x);
        
        answer.push_back(value);
    }
    
    return answer;
}