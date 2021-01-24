// 第四结构体部分
// 变量名统一使用驼峰法
// 函数结构体j 定义 枚举开头均需要大
struct TestStruct 
{
    char name[10];
    int howOld;
    char manOrWoman[10];
};

struct Inflatable
{
    char name[20];
    float volume;
    double price;
    // 测试匿名共用体
    union
    {
        int intType;
        double doubleType;
    };
    
};