
/*************************************************************************
 * 上三角与下三角进行存储
 * 超时
 * https://leetcode-cn.com/problems/gou-jian-cheng-ji-shu-zu-lcof/solution/shang-san-jiao-xia-san-jiao-by-dan-che-c-fvpu/
*======================================================================*/
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*>store{root};
    helper(root,p->val,q->val,store);
    return store[0];
}
bool helper(TreeNode* root,int a,int b,vector<TreeNode*>&store)
{
    if(root)
    {
        bool m = (root->val == a || root->val == b)?true:false;
        bool l = helper(root->left,a,b,store);
        bool r = helper(root->right,a,b,store);
        if(l && r || m && l || m && r)
            store[0] = root;

        if(m || r || l)return true;
        else return false;
    }
    return false;

}