#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int result = 45;
    
    for (int number : numbers)
        result -= number;
    
    return result;
}