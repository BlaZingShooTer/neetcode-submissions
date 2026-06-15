class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // join every point without forming a cycle and it will take
        // n-1 edges if we have n points
         int n = points.size();

         unordered_map<int,vector<pair<int,int>>> adj;

         for(int i = 0;i<n;i++){
            int x1 = points[i][0];
            int y1 = points[i][1];

            for(int j = i+1;j<n;j++){
                int x2 = points[j][0];
                int y2 = points[j][1];

                int dist = abs(x2 - x1) + abs(y2 -y1);

                adj[i].push_back({dist,j});
                adj[j].push_back({dist,i});
            }
         }

         int res = 0;

         unordered_set<int> visit;

         priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> minH;

         minH.push({0,0});

         while(visit.size()<n){
            auto curr = minH.top();
            minH.pop();

            int cost = curr.first;
            int i = curr.second;
            if(visit.count(i)) continue;

            res += cost;

            visit.insert(i);

            for(const auto k : adj[i]){
                int k1 = k.first;
                int k2 = k.second;

                if(!visit.count(k2)){
                    minH.push({k1,k2});
                }
            }
         }

         return res;
    }
};
