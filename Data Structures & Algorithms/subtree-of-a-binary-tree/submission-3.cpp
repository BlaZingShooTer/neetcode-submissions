class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;  // empty root can't have a subtree

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* el = q.front();
            q.pop();

            if (el->val == subRoot->val) {
                if (SameTree(el, subRoot)) return true;
            }

            if (el->left) q.push(el->left);
            if (el->right) q.push(el->right);
        }

        return false;  // no match found
    }

    bool SameTree(TreeNode* q , TreeNode* p) {
        if (!q && !p) return true;
        if (!q || !p) return false;
        if (q->val != p->val) return false;

        return SameTree(q->left, p->left) && SameTree(q->right, p->right);
    }
};
