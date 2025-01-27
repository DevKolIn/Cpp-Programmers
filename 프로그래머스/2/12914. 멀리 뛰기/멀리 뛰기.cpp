#include <string>
#include <vector>

using namespace std;

long long solution(int n) {  
    if (n <= 2)
    {
        return n;
    }
    
    vector<long long> JumpCounts(n, 0);
    JumpCounts[0] = 1;
    JumpCounts[1] = 2;
    
    for (int i = 2; i < n; i++)
    {
        JumpCounts[i] = (JumpCounts[i - 2] + JumpCounts[i - 1]) % 1234567;
    }
    
    return JumpCounts[n - 1];
}