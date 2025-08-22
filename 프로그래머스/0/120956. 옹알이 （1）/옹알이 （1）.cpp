#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<string> babblings) {
    vector<string> words = {"aya", "ye", "woo", "ma"};
    
    int ret = 0;
    for (string babbling : babblings)
    {
        for (int i = 0; i < words.size(); ++i)
        {
            size_t pos = babbling.find(words[i]);
            
            if (pos == 0)
            {
                babbling.erase(pos, words[i].length());
                i = -1;
            }
        }
        
        if (babbling.empty())
            ret++;
    }
    
    return ret;
}