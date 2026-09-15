/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if(root == nullptr) return false;
        
        if(root!= nullptr && subRoot == nullptr) return true;
        

        if(dfs(root,subRoot)) return true;

        return isSubtree(root->right , subRoot) || isSubtree(root->left, subRoot);
    }

    bool dfs(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;

        if(!q || !p) return false;

        if(p->val != q->val) return false;

        return dfs(p->left, q->left) && dfs(p->right , q->right);
    }
};
