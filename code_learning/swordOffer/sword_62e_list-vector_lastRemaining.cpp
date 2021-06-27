// 0627 记录
// 使用链表存在 如果删除步长为1的时候不方便索引到上一个元素
// erase擦除之所以引起迭代器错位是因为使用不当

int lastRemaining(int n, int m) {

    vector<int>store;
    // 存储起来
    for(int i = 0;i<n;i++)
        store.push_back(i);

    auto ite = store.begin();
    while(store.size() != 1)
    {
        for(int i = 0;i<m-1;i++)// 这里用循环来移动ite防止野指针
        {
            ite += 1;
            if(ite == store.end())ite = store.begin();
        }
        n -= 1;
        ite = store.erase(ite);
        if(ite == store.end())ite = store.begin();// 删除保险 检测一下是否删除最后一个导致野指针
    }
    return store[0];
}



// 0317 记录
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