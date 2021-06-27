/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        vector<Node*>store;
        // 中序遍历
        if(!root)return root;
        stack<Node*>sta;
        while(root || !sta.empty())
        {
            while(root)
            {
                sta.push(root);
                root = root->left;
            }
            root = sta.top();
            store.push_back(root);
            sta.pop();
            root = root->right;
        }
        Node* head = store[0];

        for(int i=0;i<store.size()-1;i++)
        {
            store[i]->right = store[i+1];
            store[i+1]->left = store[i];
        }
        store[store.size()-1]->right = store[0];
        store[0]->left = store[store.size()-1];
        return store[0];
    }
};