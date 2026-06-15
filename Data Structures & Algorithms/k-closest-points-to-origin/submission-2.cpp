class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<long long, pair<int,int>>> pq;

        for(int i = 0; i < points.size(); i++) {

            int x = points[i][0];
            int y = points[i][1];

            long long dist = 1LL * x * x + 1LL * y * y;

            pq.push({dist, {x, y}});

            // Maintain only k elements
            if(pq.size() > k) {
                pq.pop();  // remove farthest
            }
        }

        vector<vector<int>> ans;

        while(!pq.empty()) {
            ans.push_back({pq.top().second.first,
                           pq.top().second.second});
            pq.pop();
        }

        return ans;
    }
};
