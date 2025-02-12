#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

int solution(vector<int> toppings) {
    set<int> left;
    unordered_map<int,int> right;
        
    for (int topping : toppings)
    {
        right[topping]++;
    }
    
    int answer = 0;
    for (int topping : toppings)
    {
        left.emplace(topping);
        right[topping]--;
        
        if (right[topping] == 0)
        {
            right.erase(topping);
        }
        
        if (left.size() == right.size())
        {
            answer++;
        }
    }
    
    return answer;
}