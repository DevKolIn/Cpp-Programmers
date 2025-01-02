#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int currentCoke) {
    int answer = 0;
    int receiveCoke = 0;
    int remainCoke = 0;
    
    while (currentCoke >= a)
    {
        receiveCoke = currentCoke / a * b;
        remainCoke = currentCoke % a;
        currentCoke = receiveCoke + remainCoke;
        answer += receiveCoke;
    }
    
    return answer;
}