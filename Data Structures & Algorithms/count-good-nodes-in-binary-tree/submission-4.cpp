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
    int goodNodes(TreeNode* root) {

        return dfs(root,root->val);
        
    }

    int dfs(TreeNode* n , int val){
        if(n == nullptr) return 0;

        int r = 0;
        if(n->val >= val){
            r = 1;
        }

        val = max(val,n->val);

        int left = dfs(n->left,val);
        int right = dfs(n->right,val);

        return r + left + right;
    }
};
