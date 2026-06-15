class Solution {
public:
    int countComponents(int n, vector<vector<int>>& ed) {
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);

        for(int i = 0;i<ed.size();i++){
            int x1 = ed[i][0];
            int x2 = ed[i][1];

            adj[x1].push_back(x2);
            adj[x2].push_back(x1);

        }
        int cnt = 0;
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,vis,adj);
            }
        }

        return cnt;
    }

    void dfs(int n , vector<int> &vis , vector<vector<int>>& adj){
        vis[n] = 1;

        for(auto it : adj[n]){
            if(!vis[it]){
                dfs(it,vis,adj);
            }
        }
    }
};
