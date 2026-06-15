class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long long, pair<int,int>>> pq;

        for (auto &p : points) {
            long long d = 1LL * p[0] * p[0] + 1LL * p[1] * p[1];
            pq.push({d, {p[0], p[1]}});
            if (pq.size() > k) pq.pop();
        }

        vector<vector<int>> ans;
        while (!pq.empty()) {
            auto [d, coords] = pq.top();
            ans.push_back({coords.first, coords.second});
            pq.pop();
        }
        return ans;
    }
};
