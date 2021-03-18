int numWays(int n) {
    if(n == 0)return 1;
    if(n == 1)return 1;
    vector<int>store(101,0);
    store[0] = 1;
    store[1] = 1;
    for(int i = 2;i<=n;i++)
        store[i] = (store[i-1]+store[i-2])%1000000007;
    return store[n];
}