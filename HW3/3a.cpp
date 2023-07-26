class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result; // Final result 
        vector<vector<int>> graph(numCourses, vector<int>()); // Graph for course dependencies
        vector<int> inDegree(numCourses, 0); // # of prerequisites for course

        // Build the course dependency graph and calculate prerequisites count
        for (const auto& edge : prerequisites) {
            int ai = edge[0]; // Course that depends on bi
            int bi = edge[1]; // Prerequisite for ai
            graph[bi].push_back(ai); // Add ai to list of courses dependent on bi
            inDegree[ai]++; // Increase prerequisites count for ai
        }

        queue<int> q; // Queue for BFS
        // Add all courses with no prerequisites to the queue
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        // BFS to find the order that courses can be taken
        while (!q.empty()) {
            int curr = q.front(); // current course
            q.pop();
            result.push_back(curr); // Add current course to result since its taken

            // Decrease prerequisites count for neighbors and enqueue them if count is 0
            for (int neighbor : graph[curr]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If all courses can be taken then we return the result
        if (result.size() == numCourses) {
            return result;
        } else {
            return vector<int>(); // returns empty vector if not
        }
    }
};
