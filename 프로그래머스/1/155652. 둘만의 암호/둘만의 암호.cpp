#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";

    // skip에 포함된 문자들을 set으로 저장 (빠른 검색을 위해)
    set<char> skipSet(skip.begin(), skip.end());

    for (char ch : s) {
        char current = ch;

        // index 만큼 이동하며 skip 처리
        for (int i = 0; i < index; ) {
            current++; // 다음 문자로 이동
            if (current > 'z') { // z를 넘어가면 a로 순환
                current = 'a';
            }

            // skip에 포함되지 않는 문자일 때만 카운트 증가
            if (skipSet.find(current) == skipSet.end()) {
                i++;
            }
        }

        answer += current; // 변환된 문자 추가
    }

    return answer;
}