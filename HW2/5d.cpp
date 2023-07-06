class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
          if (root->val == val){ //checks if the node we are at is the value
              return root;
          }
          if (root->val > val && root->left != nullptr){ // recursively moves to left node if the value is less than the root 
              return searchBST(root->left, val);
          }
          if (root->val < val && root->right != nullptr){// recursively moves to right node if the value is greater than the root 
              return searchBST(root->right, val);
          }
          return nullptr; //if the node is not found return nullptr
    }
};

