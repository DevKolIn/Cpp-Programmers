int solution(int num) {
    int result = -1;
    long long numTemp = num;
    
    for (int i = 0; i < 500; i++)
    {
        if (numTemp == 1)
        {
            result = i;
            break;
        }
        
        if (numTemp % 2 == 0)
        {
            numTemp /= 2;
        }
        else
        {
            numTemp *= 3;
            numTemp += 1;
        }
    }
        
    return result;
}