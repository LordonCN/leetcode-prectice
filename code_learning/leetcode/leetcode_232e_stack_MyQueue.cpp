#include <iostream>
#include <string>
#include <stack>
using namespace std;

/*************************************************************************
 * use stack to achieve queue
 *======================================================================*/

class MyQueue {
private:
    stack<int> insta,outsta;
    int temp;

public:
    /** Initialize your data structure here. */
    MyQueue() = default;
    ~MyQueue() = default;

    /** Push element x to the back of queue. */
    void push(int x) {
        insta.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(!insta.empty())
        {
            outsta.push(insta.top());
            insta.pop();
        }
        temp = outsta.top();
        outsta.pop();
        while(!outsta.empty())
        {
            insta.push(outsta.top());
            outsta.pop();
        }
        return temp;
    }

    /** Get the front element. */
    int peek() {
        while(!insta.empty())
        {
            outsta.push(insta.top());
            insta.pop();
        }
        temp = outsta.top();
        while(!outsta.empty())
        {
            insta.push(outsta.top());
            outsta.pop();
        }
        return temp;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return insta.empty();
    }
};


int main()
{
    MyQueue stackQueue ;
    stackQueue.push(4);
    stackQueue.push(1);
    stackQueue.push(6);
    stackQueue.push(8);
    cout<<stackQueue.empty()<<endl;
    cout<<stackQueue.peek()<<endl;
    cout<<stackQueue.pop()<<endl;
    cout<<stackQueue.peek()<<endl;




    return 0;
}