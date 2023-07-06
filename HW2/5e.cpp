class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr){ // if the tree is empty then insert node
            return new TreeNode(val);
        }
        if (root->val < val){ //if the node is greater than the value, recursivley move to the right side of the tree 
            root->right = insertIntoBST(root->right, val);
        }
        if (root->val > val){ //if the node is less than the value, recursivley move to the left side of the tree 
            root->left = insertIntoBST(root->left, val);
        }
        return root;
    }
};
