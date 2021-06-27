
// 这个本地跑可以 提交就内存报错 不知道为啥
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>pu;
        stack<int>po;
        pu.push(INT_MAX);// 安全 防止top取出来空值
        po.push(INT_MAX);
        po.push(popped[0]);
        int idx = 1;
        for(int i = 0;i<pushed.size();i++)// 主循环是对于 pushed
        {
            pu.push(pushed[i]);
            if(po.top() == INT_MAX)
                po.push(popped[idx++]);
            // 处理与pop相同的部分 能推出就推
            while(pu.top() != INT_MAX && po.top() != INT_MAX && pu.top() == po.top())
            {
                po.pop();pu.pop();
                if(po.top() == INT_MAX)
                    po.push(popped[idx++]);
            }
        }
        if(pu.top() == INT_MAX || pu.empty())return true;
        else return false;

    }
};