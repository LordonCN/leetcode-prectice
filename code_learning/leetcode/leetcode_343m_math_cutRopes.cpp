
// 从算数几何平均值来算
// 切出来3多乘积越大 存在2 3这两个特殊情况

int cuttingRope(int n) {
    // 这里n = 2，n = 3都要特殊考虑一下 2(1*1)    3(1*2)
    if(n <= 3)return n-1;
    // 这里就按照以3为标准拆分 符合算数几何均值
    int s = n/3,t = n%3;
    if(t == 0) return pow(3,s);
    else if (t == 1) return pow(3,s-1)*2*2;
    else return pow(3,s)*2;
}

