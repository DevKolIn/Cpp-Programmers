#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    return to_string(a) + to_string(b) > to_string(b) + to_string(a);
}

string solution(vector<int> numbers) {
    unsigned long long maxValue = 0;
    
    sort(numbers.begin(), numbers.end(), compare);
    
    if (numbers[0] == 0) return "0";

    string answer = "";
    for (int num : numbers) {
        answer += to_string(num);
    }
  
    return answer;
}