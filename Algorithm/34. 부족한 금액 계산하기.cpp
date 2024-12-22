long long solution(int price, int money, int count)
{
    long long result = 0;
    long long cost = 0;
    
    for (int i = 1; i <= count; i++)
    {
        cost += price * i;
    }
    
    if (money < cost)
    {
        result = cost - money;
    }
    else
    {
        result = 0;
    }
    
    return result;
}