class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* curr = root;
        TreeNode* parent = nullptr;

        // Find the node
        while (curr && curr->val != key) {
            parent = curr;

            if (key < curr->val)
                curr = curr->left;
            else
                curr = curr->right;
        }

        // Key not found
        if (curr == nullptr)
            return root;

        // Case 1 & 2: Node has at most one child
        if (curr->left == nullptr || curr->right == nullptr) {
            TreeNode* child;

            if (curr->left != nullptr)
                child = curr->left;
            else
                child = curr->right;

            // Deleting root
            if (parent == nullptr)
                return child;

            if (parent->left == curr)
                parent->left = child;
            else
                parent->right = child;

            return root;
        }

        // Case 3: Node has two children
        TreeNode* successorParent = curr;
        TreeNode* successor = curr->right;

        // Find smallest node in right subtree
        while (successor->left != nullptr) {
            successorParent = successor;
            successor = successor->left;
        }

        // Copy successor value
        curr->val = successor->val;

        // Delete successor
        if (successorParent->left == successor)
            successorParent->left = successor->right;
        else
            successorParent->right = successor->right;

        return root;
    }
};