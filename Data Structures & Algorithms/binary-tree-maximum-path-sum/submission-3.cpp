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


    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;

        dfs(root,res);

        return res;
    }

    int dfs(TreeNode* root , int &val){

        if(root == nullptr) return 0;

        int left = max(0,dfs(root->left,val));
        int right = max(0,dfs(root->right,val));

        int curr = left + right + root->val;

        val  = max(val , curr);

        return root->val + max(left,right);

        
    }
};
