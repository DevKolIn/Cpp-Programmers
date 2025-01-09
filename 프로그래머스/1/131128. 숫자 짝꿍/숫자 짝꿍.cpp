#include <string>
#include <vector>

using namespace std;

string solution(string X, string Y) {
    // 숫자 0~9의 개수를 저장하는 배열
    vector<int> countX(10, 0);
    vector<int> countY(10, 0);

    // X와 Y의 각 숫자의 개수 카운트
    for (char c : X) {
        countX[c - '0']++;
    }
    for (char c : Y) {
        countY[c - '0']++;
    }

    // 공통으로 나타나는 숫자 추출
    string result = "";
    for (int i = 9; i >= 0; --i) { // 큰 숫자부터 탐색
        int commonCount = min(countX[i], countY[i]); // 짝지을 수 있는 개수
        result += string(commonCount, '0' + i);     // 공통 숫자를 결과에 추가
    }

    // 결과 처리
    if (result.empty()) {
        return "-1"; // 공통 숫자가 없으면 -1 반환
    }
    if (result[0] == '0') {
        return "0"; // 결과가 0으로만 구성되면 0 반환
    }

    return result; // 짝꿍 반환
}