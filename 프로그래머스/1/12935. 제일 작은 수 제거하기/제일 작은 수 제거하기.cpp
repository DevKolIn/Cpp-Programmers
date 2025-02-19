#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    if (arr.size() == 1) return {-1};
    
    int minValue = *min_element(arr.begin(), arr.end());
    
    arr.erase(remove(arr.begin(), arr.end(), minValue), arr.end());
    
    return arr;
}
