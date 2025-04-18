#include <string>
#include <stack>

std::string solution(std::string number, int k) {
    std::string answer;
    int len = number.size();
    int keep = len - k;

    for (char digit : number) {
        while (!answer.empty() && answer.back() < digit && k > 0) {
            answer.pop_back();
            k--;
        }
        answer.push_back(digit);
    }

    answer.resize(keep);

    return answer;
}