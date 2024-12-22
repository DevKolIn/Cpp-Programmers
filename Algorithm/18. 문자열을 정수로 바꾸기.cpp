int solution(string str) {
    int sum = 0;
    int sign = 1;
    const char* arr = str.c_str();
    
    if (arr[0] == '+')
    {
        arr++;
    }
    if (arr[0] == '-')
    {
        arr++;
        sign = -1;
    }
    
    while (*arr)
    {
        sum *= 10;
        sum += *arr - '0';
        arr++;
    }
    
    return sum * sign;
}