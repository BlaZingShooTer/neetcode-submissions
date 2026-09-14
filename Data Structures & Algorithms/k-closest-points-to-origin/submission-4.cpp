class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<long long,pair<int,int>>> pq;

        for(auto pt : points){

            int x = pt[0];
            int y = pt[1];

            long long dist = x*x + y*y;

            pq.push({dist,{x,y}});

            if(pq.size() > k ){
                pq.pop();
            }
        }

        vector<vector<int>> ans;

        while(!pq.empty()){

            int x = pq.top().second.first;
            int y = pq.top().second.second;

            pq.pop();

            ans.push_back({x,y});
        }

        return ans;
    }
};
