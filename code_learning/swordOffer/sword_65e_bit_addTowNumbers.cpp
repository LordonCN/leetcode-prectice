
// 从算数几何平均值来算
// 切出来3多乘积越大 存在2 3这两个特殊情况

int addTowNumbers(int a,int b) {
    while(b != 0){
        int c = unsigned (a & b) << 1;//进位位  a b这个位置相同了 相加后会进位
        a ^= b;//半加器 如果b有a不同的地方 加进来 有相同的则剔除(c为进位)
        b = c;// 进位喽
    }


}
