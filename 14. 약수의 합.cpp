int solution(int num) {
    int sum = 0;
    int rootNum = sqrt(num);
    
    for (int div = 1; div <= rootNum; div++)
    {
        if (num % div == 0)
        {
            sum += div;
            
            int quotient = num / div;
            if (quotient != div)
            {
                sum += quotient;
            }
        }
    }
    return sum;
}