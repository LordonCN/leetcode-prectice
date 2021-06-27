
// 对于长度小于等于3的情况来说 直接返回数值即可
// n长度的数字每次递减3 直到n小于3
// 其实也是满足了数学的方法
// 从算数几何平均值来算
int cuttingRope(int n) {
    if (n == 2) return 1;
    if (n == 3) return 2;

    long result = 1;
    while (n > 4) {
        n -= 3;
        result *= 3;
        result % 10000007;
    }
    return (int) (n * result % 10000007);// 剩余的1 或者2 再乘上
}