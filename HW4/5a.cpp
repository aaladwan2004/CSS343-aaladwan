class Solution {
public:
int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    int totalCost = 0;
    int currentNode = 0;
    int connectedPoints = 0;
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>> pq; // distance, index
    
    while (connectedPoints < n - 1) {
        visited[currentNode] = true;

        // distance for unvisited points and push to pq
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int distance = abs(points[currentNode][0] - points[i][0]) + abs(points[currentNode][1] - points[i][1]);
                pq.push({-distance, i});
            }
        }
        
        // skip visited nodes in the queue
        while (visited[pq.top().second]) {
            pq.pop();
        }
        
        totalCost -= pq.top().first;
        currentNode = pq.top().second;
        pq.pop();
        connectedPoints++;
    }

    return totalCost;
}
