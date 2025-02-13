#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    auto iter = find(seoul.begin(), seoul.end(), "Kim");
    return "김서방은 " + to_string(distance(seoul.begin(), iter)) + "에 있다";;
}