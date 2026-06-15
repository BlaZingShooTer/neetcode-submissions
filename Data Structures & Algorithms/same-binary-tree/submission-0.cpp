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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;

        q1.push(p);
        q2.push(q);


        while(!q1.empty()){
            int s = q1.size();

            for(int i = 0;i<s;i++){
                TreeNode* el1 = q1.front();
                q1.pop();
                TreeNode* el2 = q2.front();
                q2.pop();
                if (!el1 && !el2) continue;
                if(!el1 || !el2 || el1->val != el2->val) return false;

                q1.push(el1->left);
                q1.push(el1->right);

                q2.push(el2->left);
                q2.push(el2->right);

            }
        }

        return true; 

    }
};
