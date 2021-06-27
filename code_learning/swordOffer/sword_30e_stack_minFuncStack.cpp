class MinStack {
public:
    stack<int>s;
    stack<int>mins;
    /** initialize your data structure here. */
    MinStack() {
        // while(!s.empty())s.pop();
        // while(!mins.empty())mins.pop();
        mins.push(INT_MAX);// 这里如果不先push一个最大值那么后面push的时候会有内存报错
    }

    void push(int x) {
        s.push(x);
        mins.push(std::min(mins.top(), x));
    }

    void pop() {

        s.pop();

        mins.pop();
    }

    int top() {
        return s.top();
    }

    int min() {
        return mins.top();
    }
};