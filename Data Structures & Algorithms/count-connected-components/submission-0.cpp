class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int cnt = 0;
        vector<int> vis(n,0);

        vector<vector<int>> adj(n+1);

        for(int i = 0;i<edges.size();i++){
            int x = edges[i][0];
            int y = edges[i][1];

            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        for(int i = 0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                cnt++;
            }
        }

        return cnt;

    }


    void dfs(int i, vector<vector<int>>& adj,vector<int>& vis){
        
        vis[i] = 1;

        for(auto it : adj[i]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }
};
