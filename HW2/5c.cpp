//Pre Order
class Solution {
public:
    vector<int> PreOrder;
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr) return PreOrder;
        PreOrder.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return PreOrder;
        }
};

//In Order
class Solution {
public:
    vector <int> inOrder;
    vector<int> inorderTraversal(TreeNode* root) {
       if (root == nullptr) return inOrder;
        inorderTraversal(root->left);
        inOrder.push_back(root->val);
        inorderTraversal(root->right);
        return inOrder; 
    }
};

// Post Order
class Solution {
public:
    vector <int> PostOrder;
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) return PostOrder;
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        PostOrder.push_back(root->val);
        return PostOrder; 
    }
};

//the only thing that chagnes is which is visted first, we move the when we vist the root accordingly
