class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> ans;
        
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        for(int i = 0;i<pre.size();i++){
            int x1 = pre[i][0];
            int x2 = pre[i][1];

            adj[x2].push_back(x1);
        }

        for(int i =0;i<n;i++){
            if(vis[i] == 0 && !dfs(i,adj,ans,vis)){
                return {};
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

    bool dfs(int i ,vector<vector<int>>& adj, vector<int> &ans ,vector<int> &vis  ){
        if(vis[i] == 1) return false;
        if(vis[i]== 2) return true;

        vis[i] = 1;

        for(auto p : adj[i]){
            if(!dfs(p,adj,ans,vis)){
                return false;
            }
        }

        vis[i] = 2;
        ans.push_back(i);
        return true;
    }
};
