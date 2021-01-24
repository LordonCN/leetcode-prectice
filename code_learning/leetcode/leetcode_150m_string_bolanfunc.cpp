#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

/* -------------------------------------------
 * switch 用法
 * char to int 通过做差解决
 * vector的引用方法 stack引用方法
 * ------------------------------------------*/
int calculate(int result,stack<int>& temp,char sign)
{
    return result;
}

int niBolanFunc(const vector<char>& tokens)
{
    int result = 0;
    stack<int> tempNumber;
    for(int i = 0;i < tokens.size(); i++)
    {
        switch(tokens[i])
        {
            case '+': {
                int number1 = tempNumber.top();
                tempNumber.pop();
                int number2 = tempNumber.top();
                tempNumber.pop();
                result = number1 + number2;
                tempNumber.push(result);
                break;
            }
            case '-': {
                int number1 = tempNumber.top();
                tempNumber.pop();
                int number2 = tempNumber.top();
                tempNumber.pop();
                result = number1 - number2;
                tempNumber.push(result);
                break;
            }
            case '*': {
                int number1 = tempNumber.top();
                tempNumber.pop();
                int number2 = tempNumber.top();
                tempNumber.pop();
                result = number1 * number2;
                tempNumber.push(result);
                break;
            }
            case '/': {
                int number1 = tempNumber.top();
                tempNumber.pop();
                int number2 = tempNumber.top();
                tempNumber.pop();
                result = number1 / number2;
                tempNumber.push(result);
                break;
            }
            default: {
                tempNumber.push(tokens[i] - '0');
                break;
            }
        }
    }
    return result;
}


int main()
{
    vector<char> nums;

    nums.push_back('4');
    nums.push_back('4');
    nums.push_back('+');

    int result;
    result = niBolanFunc(nums);

    return 0;
}






