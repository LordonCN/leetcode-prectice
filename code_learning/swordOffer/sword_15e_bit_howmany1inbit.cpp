
// 从算数几何平均值来算
// 切出来3多乘积越大 存在2 3这两个特殊情况

int hammingWeight(uint32_t n) {
    int sum = 0;
    while(n){
        sum += n&1;
        n = n>>1;
    }
    return sum;

}
