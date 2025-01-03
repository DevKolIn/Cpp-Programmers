#include <string>
#include <vector>
#include <algorithm>

using namespace std;

std::string solution(std::vector<std::string> cards1, std::vector<std::string> cards2, std::vector<std::string> goal) {
    int idx1 = 0, idx2 = 0;

    for (const auto& word : goal) {
        if (idx1 < cards1.size() && cards1[idx1] == word) {
            ++idx1;
        } else if (idx2 < cards2.size() && cards2[idx2] == word) {
            ++idx2;
        } else {
            return "No";
        }
    }

    return "Yes";
}