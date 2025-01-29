#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int solution(vector<int> elements) {
    set<int> set;
    
    int size = elements.size();
    
    for (int num = 1; num <= size; ++num)
    {
        for (int idx = 0; idx < size; ++idx)
        {
            int sum = 0;
            for (int i = 0; i < num; ++i)
            {
                int elementIndex = (idx + i) % size;
                sum += elements[elementIndex];
            }
            set.insert(sum);
        }
    }
    
    return set.size();
}