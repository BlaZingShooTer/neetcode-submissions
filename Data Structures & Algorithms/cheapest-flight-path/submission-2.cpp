class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       vector<vector<pair<int,int>>> adj(n);

        for(auto it : flights){
            adj[it[0]].push_back({it[1], it[2]});
        }

        queue<pair<int,pair<int,int>>> q;

        vector<int> dist(n,1e9) ;
        q.push({0,{src,0}});
        dist[src]= 0;

        while(!q.empty()){
            auto it = q.front();

            q.pop();

            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stops > k) continue;

            for(auto p : adj[node]){
                int ew = p.second;
                int dt = p.first;

                if(ew + cost < dist[dt] && stops <= k){
                    dist[dt] = ew + cost;
                    q.push({stops + 1,{dt,ew+cost}});
                }
            }

            
        }

        if(dist[dst] < 1e9) return dist[dst];
        
        return -1;





    }
};
