class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p,q);
    }

    bool dfs(TreeNode* p , TreeNode* q){

        if(!p && !q) return true;

        if(!p || !q) return false;

        if(p->val != q->val) return false;

        return dfs(p->left , q->left) && dfs(p->right , q->right);
    }
};