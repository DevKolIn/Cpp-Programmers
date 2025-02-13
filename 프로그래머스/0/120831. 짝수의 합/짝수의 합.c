#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int sum = 0;
    for (int num = 2; num <= n; num+=2)
        sum += num;   
    
    return sum;
}