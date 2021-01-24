#include <iostream>
#include <string>

using namespace std;

class TV
{
private:
    int channel;
    int voice;
    string name;
    int type;
    int state;

public:
    TV(){voice = 10;};
    ~TV() = default;

    friend class Remote;

    enum{on,off};
    void setTvName(string tvname){name = tvname;};
    void setType(int number){type = number;};
    void setState(){state = (state == on)?off:on;};
    void setValue(int value){voice = value;};

};


// 这里以遥控器控制电视 遥控器作为友元类进行解释 (友元函数查看cpp primer plus 涉及前向声明)
// 友元函数能够对所有的私有变量以及保护变量进行访问
// 声明可以放在任何位置
class Remote
{
private:
    string name;
public:
    Remote() = default;

    void controlVoice(TV &t){t.setValue(6);};

};







int main()
{

    return 0;
}