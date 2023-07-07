// refrenced Solution in cpp by Javohir_Xoldorov

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // create vector for answer
        vector<vector<int>> ans;
        
        // create vector of pairs to store the squared distance and point
        vector<pair<int, vector<int>>> distPointPairs;
        
        // calculate the squared distance and store the points in the vector
        for (int i = 0; i < points.size(); i++) {
            int squaredDist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            distPointPairs.push_back({squaredDist, {points[i][0], points[i][1]}});
        }
        
        // sort vector
        sort(distPointPairs.begin(), distPointPairs.end());
        
        // add the closest points to vector
        int j = 0;
        while (k-- > 0) {
            ans.push_back(distPointPairs[j++].second);
        }
        
        return ans;
    }
};
