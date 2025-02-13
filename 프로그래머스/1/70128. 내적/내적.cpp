#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int result = 0;
    int arrSize = a.size();
    
    for (int i = 0; i < arrSize; i++)
    {
        result += a[i] * b[i];
    }
    
    return result;
}