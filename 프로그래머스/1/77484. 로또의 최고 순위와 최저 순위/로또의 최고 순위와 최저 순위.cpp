#include <vector>
#include <algorithm>

using namespace std;

int getRank(int matchedCount)
{
    if (matchedCount < 2) return 6;
    else if (matchedCount < 3) return 5;
    else if (matchedCount < 4) return 4;
    else if (matchedCount < 5) return 3;
    else if (matchedCount < 6) return 2;
    else return 1;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    int zeroCount = 0;
    // 0개의 카운트를 센다.
    for (int lotto : lottos)
    {
        if (lotto == 0)
            ++zeroCount;
    }
    
    // 맞춘 개수를 센다.
    int matchedCount = 0;
    for (auto it = win_nums.begin(); it < win_nums.end(); ++it)
    {
        auto lottoIt = find(lottos.begin(), lottos.end(), *it);
        if (lottoIt != lottos.end())
        {
            ++matchedCount;
        }
    }
    
    // 숫자 0이 모두 맞았음을 가정한다.
    answer.push_back(getRank(matchedCount + zeroCount));
    
    // 숫자 0이 모두 틀렸음을 가정한다.
    answer.push_back(getRank(matchedCount));
    return answer;
}