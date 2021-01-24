#include <iostream>
#include <string>

using namespace std;

/* -------------------------------------------
 * 定义二维数组
 * 个十百千四位
 * 每一位9个数字
 * 然后对应查表即可
 * string 追加使用append
 * 前面添加用+号 roman = "string" + roman;
 * ------------------------------------------*/

string intToRoman(int num)
{
    char* dictionary[4][10] = {
            {"","I","II","III","IV","V","VI","VII","VIII","IX"},
            {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
            {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
            {"","M","MM","MMM"}
    };

    string roman;
    roman.append(dictionary[3][num / 1000]); // 取第一位
    roman.append(dictionary[2][num / 100 % 10]); // 取出第2位
    roman.append(dictionary[1][num / 10 % 10]);
    roman.append(dictionary[0][num % 10]);

    return roman;
}

int main()
{
    string s;
    int num = 3231; // 1-3000

    // 特殊情况判断
    if (!num) return 0;

    s = intToRoman(num);


    return 0;
}




