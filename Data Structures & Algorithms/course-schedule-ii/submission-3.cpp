class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses,0);
        vector<int> ans;

        vector<vector<int>> adj(numCourses);

        for(auto p : prerequisites){
            int u = p[0];
            int v = p[1];
            adj[v].push_back(u);
        }

        for(int i = 0;i<numCourses;i++){
            if(vis[i] == 0 && !dfs(i,adj,vis,ans)){
                return {};
            }
        }

        reverse(ans.begin(),ans.end());
        return ans;

    }

    bool dfs(int n , vector<vector<int>>& adj , vector<int> &vis ,vector<int> &ans){
        if(vis[n] == 1) return false;
        if(vis[n] == 2) return true;

        vis[n] = 1;
        
        for(auto it : adj[n]){
            if(!dfs(it , adj, vis,ans)) return false;    
        }

        vis[n] = 2;
        ans.push_back(n);
        return true;
    }
};
