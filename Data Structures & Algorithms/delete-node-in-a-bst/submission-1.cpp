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



    TreeNode* deleteNode(TreeNode* root, int key) {


        TreeNode* curr = root;
        TreeNode* parent = nullptr;

        while(curr && curr->val != key){

            if(curr->val > key) {
                parent = curr;
                curr = curr->left;
            }
            else{
                parent =curr;
                curr = curr->right;
            }
        }

        if(curr == nullptr) return root;


        // 1 child

        if(curr->left == nullptr || curr->right == nullptr){

            TreeNode* child;

            if(curr->left == nullptr) child = curr->right;
            else{
                child = curr->left;
            }
            
            if(parent == nullptr) return child;

            if(parent->left == curr){
                parent->left = child;
            }
            else{
                parent->right = child;
            }

            return root;
        }

        TreeNode* sp = curr;
        TreeNode* s = curr->right;

        while(s->left!= nullptr){
            sp = s;
            s = s->left;
        }

        curr->val = s->val;

        if(sp->left == s){
            sp->left = s->right;
        }
        else{
            sp->right = s->right;
        }

        return root;
        
    }
};