class Solution {
public:
    Node* dfs(Node* cur, unordered_map<Node*, Node*>& mp) {
        vector<Node*> neighbour; // vecor with coloned values
        Node* clone = new Node(cur->val); // clone node with current node value
        mp[cur] = clone; // Store the clone node in the map with the original node as the key

        // checks if nieghbor is cloned, either clones it or uses the copy
        for (auto it : cur->neighbors) {
            if (mp.find(it) != mp.end()) {
                neighbour.push_back(mp[it]); 
            } else {
                neighbour.push_back(dfs(it, mp)); 
            }
        }
        
        clone->neighbors = neighbour; // cloned nieghbor to current 
        return clone; // return cloned node
    }
    
    // clones the values if needed, returns clone
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> mp; 
        if (node == NULL)
            return NULL;
        if (node->neighbors.size() == 0) {
            Node* clone = new Node(node->val); 
            return clone; 
        }
        return dfs(node, mp); // DFS to clone the graph using the map 
    }
};
