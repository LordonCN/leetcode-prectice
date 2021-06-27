vector<int> levelOrder(TreeNode* root) {
    return treeBFS(root);
}


vector<int> treeBFS(TreeNode* root) {
    // 创关键队列保存
    queue<TreeNode *> que;
    // 若不为空添加头结点进去
    if (root) que.push(root);
    vector<int> result;
    // 直到所有遍历完成
    while (!que.empty()) {
        TreeNode *node = que.front();
        que.pop();
        result.push_back(node->val);
        if (node->left) que.push(node->left);
        if (node->right) que.push(node->right);
    }
    return result;
}

vector<vector<int>> levelOrder(TreeNode* root) {

    return treeBFS(root);
}
vector<vector<int>> treeBFS(TreeNode* root) {
    // 创关键队列保存
    queue<TreeNode*> que;
    // 若不为空添加进去
    if (root) que.push(root);
    vector<vector<int>> result;
    // 终止判断条件 只有所有都遍历完了才会结束循环
    while (!que.empty()) {
        // 这里记住pop次数 到这里的时候queue中包含的都是此深度的所有节点值
        int size = que.size();
        // 保存当前深度数值
        vector<int> vec;
        // 这里一定要使用固定大小size，不要使用que.size()，因为que.size是不断变化的
        for (int i = 0; i < size; i++) {
            TreeNode* node = que.front();
            que.pop();
            vec.push_back(node->val);
            if (node->left) que.push(node->left);
            if (node->right) que.push(node->right);
        }
        result.push_back(vec);
    }
    return result;
}

vector<vector<int>> levelOrder(TreeNode* root) {

    return treeBFS_2d(root);
}



vector<vector<int>> treeBFS_2d(TreeNode* root) {
    // 创关键队列保存
    queue<TreeNode*> que;
    // 若不为空添加进去
    if (root) que.push(root);
    vector<vector<int>> result;
    int i = 1;
    // 终止判断条件 只有所有都遍历完了才会结束循环
    while (!que.empty()) {
        // 这里记住pop次数 到这里的时候queue中包含的都是此深度的所有节点值
        int size = que.size();
        // 保存当前深度数值
        vector<int> vec;
        // 这里一定要使用固定大小size，不要使用que.size()，因为que.size是不断变化的
        for (int i = 0; i < size; i++) {
            TreeNode* node = que.front();
            que.pop();
            vec.push_back(node->val);
            if (node->left) que.push(node->left);
            if (node->right) que.push(node->right);
        }
        if(i%2 == 0)
            reverse(vec.begin(),vec.end());
        i += 1;
        result.push_back(vec);
    }
    return result;
}