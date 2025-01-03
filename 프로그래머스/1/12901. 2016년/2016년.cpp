#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    const vector<int> month_days = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    const vector<string> week_days = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"}; 
    
    int total_days = 0;
    for (int i = 0; i < a; i++)
    {
        total_days += month_days[i];
    }
    total_days += b - 1;
    
    return week_days[total_days % 7];
}