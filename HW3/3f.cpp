// Reference: Lord_yuvi

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // adjacency list to represent the graph.
        vector<pair<int, int>> adj[n + 1];
        for (auto it : times) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        // distance array and priority queue for Dijkstra
        vector<int> dist(n + 1, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        dist[k] = 0;

        // Dijkstra to find the minimum time to reach each node from k
        while (!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for (auto it : adj[node]) {
                int adjnode = it.first;
                int d = it.second;
                if (dis + d < dist[adjnode]) {
                    dist[adjnode] = dis + d;
                    pq.push({dis + d, adjnode});
                }
            }
        }

        // Find the maximum time taken to reach any node
        int ans = -1;
        for (int i = 1; i < n + 1; i++) {
            if (dist[i] == 1e9) return -1; // cannot reach 
            else {
                ans = max(ans, dist[i]);
            }
        }

        return ans; // max time for node
    }
};
