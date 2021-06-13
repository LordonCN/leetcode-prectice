int fib(int n) {
    if(n == 0)return 0;
    if(n == 1)return 1;
    vector<int>array(101,0);

    array[0] = 0;
    array[1] = 1;
    for(int i = 2;i<=n;i++)
        array[i] = (array[i-1]+array[i-2]) % 1000000007;

    return array[n];
}