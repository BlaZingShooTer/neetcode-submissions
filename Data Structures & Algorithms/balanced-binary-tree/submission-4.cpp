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

    int f(TreeNode* root){
        if(root == nullptr){
            return 0;
        }

        int h1 = f(root->left);
        if(h1 == -1) return -1;
        int h2 = f(root->right);
        if(h2 == -1 ) return -1;

        if(abs(h1 - h2) > 1) return -1;

        return 1 + max(h1,h2);

    }

    bool isBalanced(TreeNode* root) { 

        return f(root)!= -1;

    }
};
