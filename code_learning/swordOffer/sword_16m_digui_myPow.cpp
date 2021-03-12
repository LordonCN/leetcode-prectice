double myPow(double base, int Number) {
    if(base == 1) return 1;
    if(base == -1)
        return (Number%10)%2 == 0?1:-1;
    if(Number == INT32_MIN ) return 0;

    double result = doublePow2(base,abs(Number));

    return Number>0?result:1/result;
}


double doublePow2(double base , int n)
{
    double result = 1.0;
    if(n == 0)return 1;
    if(n % 2 == 0)
        result = doublePow2(base*base,n/2);
    else
        result = doublePow2(base*base,(n-1)/2)*base;

    return result;
}
