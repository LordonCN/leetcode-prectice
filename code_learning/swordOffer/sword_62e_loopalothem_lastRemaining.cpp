// 回环检测 相比链表来说不实用
// 因为迭代器遍历 erase操作容易产生迭代器的错位
// 所以这里改用int进行位置统计
int lastRemaining(int n, int target) {
    // 超时了
    vector<int>store;
    // 存储起来
    for(int i = 0;i<n;i++)
        store.push_back(i);

    int deletePos = 0;
    while(store.size() != 1)
    {
        int step = 1;
        while(step++<target)
        {
            if(deletePos == store.size())deletePos = 0;
            deletePos += 1;
            if(deletePos == store.size())deletePos = 0;
        }
        store.erase(store.begin()+deletePos);
    }
    return store[0];
}