class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();

        vector<bool> vis(n+1,false);

        vector<vector<int>> adj(n+1);

        for(int i = 0;i<n;i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
            vector<bool> vis(n+1,false);

            if(dfs(u,-1,vis,adj)){
                return {u,v};
            }
            

        }

        return {};
    }


    bool dfs(int node,int parent, vector<bool> &vis , vector<vector<int>>& adj){
        if(vis[node]) return true;

        vis[node] = true;

        for(auto nd : adj[node]){
                if(nd == parent) continue;
                if(dfs(nd,node,vis,adj)) return true;
            
        }

        return false;
    }
};
