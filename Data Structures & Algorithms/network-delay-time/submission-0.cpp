class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        map<int,vector<pair<int,int>>> adj;
        


        for(int i = 0;i<times.size();i++){
            int x = times[i][0];
            int y = times[i][1];
            int z = times[i][2];

            adj[x].push_back({y,z});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minh;
        minh.push({0, k});

        set<int> vis;

        int t = 0;

        while(!minh.empty()){
            auto x = minh.top();
            minh.pop();

            int time = x.first;
            int node = x.second;

            if(vis.count(node)) continue;

            vis.insert(node);
            t = time;

            for(auto p : adj[node]){
                int node2 = p.first;
                int time2 = p.second;
                if(!vis.count(node2)){
                    minh.push({time2 + time , node2});
                }


            }
        }

        return vis.size() == n ? t : -1;
        
    }

    
};
