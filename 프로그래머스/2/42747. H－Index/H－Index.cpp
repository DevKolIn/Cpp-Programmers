#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool descending(int a, int b)
{
    return a > b;
}

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), descending);
    
    int index = 0;
    for (int i = 1; i <= citations.size(); ++i)
    {
        if (citations[i - 1] >= i)
            index = i;
        else
            break;
    }
    
    return index;
}