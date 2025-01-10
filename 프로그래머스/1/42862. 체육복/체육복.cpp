#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> students(n, 1);
    
    for (int num : lost)
    {
        --students[num - 1];
    }
    for (int num : reserve)
    {
        ++students[num - 1];
    }
    for (int idx = 0; idx < n; idx++)
    {
        if (students[idx] == 0)
        {
            int prevIdx = idx - 1;
            int nextIdx = idx + 1;
            
            if (prevIdx >= 0 && students[prevIdx] == 2)
            {
                answer++;
            }
            else if (nextIdx < n && students[nextIdx] == 2)
            {
                --students[nextIdx];
                answer++;
            }
        }
        else
        {
            answer++;
        }
    }
    
    return answer;
}