int solution(int num) {
    int value = 0;
    
    for (int i = 1; i < num; i++)
    {
        if (num % i == 1)
        {
            value = i;
            break;
        }
    }
    
    return value;
}