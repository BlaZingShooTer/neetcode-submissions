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
    vector<int> rightSideView(TreeNode* root) {
        
        if(!root) return {};

        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        while(!q.empty()){
            int s = q.size();

            for(int i= 0;i<s;i++){
                
                TreeNode* el = q.front();

                q.pop();

                if (i == s - 1) {
                    ans.push_back(el->val);
                }

                if (el->left) q.push(el->left);
                if (el->right) q.push(el->right);
            }
        }

        return ans;



    }
};
