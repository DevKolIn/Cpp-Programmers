#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string word) {
    /*
    가중치
    - 1번째, 1+5+25+125+625=781
    - 2번째, 1+5+25+125=156
    - 3번째, 1+5+25=31
    - 4번째, 1+5=6
    - 5번쨰, 1
    */
    vector<int> weights = {781, 156, 31, 6, 1};
    string vowels = "AEIOU";
    
    int answer = 0;
    for (int i = 0; i < word.size(); ++i)
    {
        int pos =  vowels.find(word[i]);
        answer += pos * weights[i] + 1;
    }
    
    return answer;
}