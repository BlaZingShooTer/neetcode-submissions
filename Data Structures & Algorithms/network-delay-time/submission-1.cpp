class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        set<int> vis;
        for(int i = 0;i<times.size();i++){
            int t = times[i][2];
            int u = times[i][0];
            int v = times[i][1];

            adj[u].push_back({v,t});
        }
        
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> minh;
        minh.push({0,k});

        int t = 0;


        while(!minh.empty()){
            auto x = minh.top();
            minh.pop();

            int time = x.first;
            int nd = x.second;

            if(vis.count(nd)) continue;

            vis.insert(nd);
            t =time;

            for(auto it : adj[nd]){
                int n2 = it.first;
                int t2 = it.second;

                if(!vis.count(n2)){
                    minh.push({t2+time , n2});
                }
            }

        }
        return vis.size() == n ? t : -1;

        



    }

    
    
};
