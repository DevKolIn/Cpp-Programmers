#include <string>
#include <bitset>
#include <vector>

using namespace std;

std::string decimalToBinary(int number) {
    return std::bitset<32>(number).to_string(); // 32비트로 변환
}

vector<int> solution(string s) {
    vector<int> answer(2, 0);
    
    while (s != "1")
    {
        int zeroCount = 0;
        int oneCount = 0;
        
        // 0의 개수와 1의 개수를 구한다.
        for (const char& ch : s)
        {
            if (ch == '0') ++zeroCount;
            if (ch == '1') ++oneCount;
        }
        
        // 결과값을 계산한다.
        answer[0]++;
        answer[1] += zeroCount;
        
        // 1의 개수로 새로운 s를 만든다.
        string binaryString = decimalToBinary(oneCount);
        binaryString.erase(0, binaryString.find_first_not_of('0'));
        
        s = binaryString;
    }
    
    return answer;
}