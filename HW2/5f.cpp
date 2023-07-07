class Solution {
public:
    // Helper function to find the minimum value node in a subtree
    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        // Check if the tree is empty
        if (root == nullptr) {
            return nullptr;
        }

        // Delete the node that holds the key 
        if (root->val == key) {
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            } else {
                // Two children condition
                TreeNode* successor = findMin(root->right);  // Find the successor
                root->val = successor->val;  // Replace the value 
                root->right = deleteNode(root->right, successor->val);  // Delete the successor node
            }
        // recursively traverse through the tree
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else {
            root->left = deleteNode(root->left, key);
        }

        return root;
    }
};

    
 
