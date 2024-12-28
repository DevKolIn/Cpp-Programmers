#include <string>
#include <map>
#include <cctype>
#include <iostream>

using namespace std;

struct KeywordData
{
    int length;
    int number;
};

int solution(string s) {
    map<string, KeywordData> keywordMap =
    {
        {"ze", {4, 0}},
        {"on", {3, 1}},
        {"tw", {3, 2}},
        {"th", {5, 3}},
        {"fo", {4, 4}},
        {"fi", {4, 5}},
        {"si", {3, 6}},
        {"se", {5, 7}},
        {"ei", {5, 8}},
        {"ni", {4, 9}}
    };
    
    int result = 0;
    const char *str = s.c_str();
    while (str && *str)
    {
        int num = 0;

        if (isdigit(*str))
        {
            num = *str - '0';
            str += 1;
        }
        else
        {
            string keyword = "";
            keyword += str[0];
            keyword += str[1];
            KeywordData data = keywordMap[keyword];
            num = data.number;
            str += data.length;
        }
              
        result *= 10;
        result += num;
    }
    
    return result;
}