#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> sections) {
    int answer = 0;
    
    int range = 0;
    for (int section : sections)
    {
        if (section < range)
            continue;
        
        range = section + m;
        answer += 1;
    }
    
    return answer;
}