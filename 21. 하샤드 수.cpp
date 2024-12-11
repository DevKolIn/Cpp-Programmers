bool solution(int x) {
    bool result = false;
    int sum = 0;
    int originalX = x;
    
    while (x > 0)
    {
        int remain = x % 10;
        sum += remain;
        x /= 10;
    }
    
    if (originalX % sum == 0)
        result = true;
    
    return result;
}