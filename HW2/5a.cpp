//  Refrenced "Simple and Intuitive level order traversal" by vaibhavk01

class Solution {
public:
        Node* connect(Node* root) {
        
        //checks to see if tree is empty
        if (root == nullptr) {
            return nullptr;
        }
        
        // creates queue of pointers and inserts the top level
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
           
             // does all nodes in the curr level
            for (int i = 0; i < levelSize; i++) {
                Node* current = q.front();
                q.pop();
                
                // assign the next node in the queue
                if (i < levelSize - 1) {
                    current->next = q.front();
                } else {
                    current->next = nullptr;
                }

                
                // add left and right children
                if (current->left != nullptr) {
                    q.push(current->left);
                }
                
                if (current->right != nullptr) {
                    q.push(current->right);
                }
            }
        }
        
        return root;
    }
    
};
