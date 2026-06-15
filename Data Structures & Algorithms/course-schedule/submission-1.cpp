class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses,0);
        vector<int> pathvis(numCourses,0);

        vector<vector<int>> adj(numCourses);

        for(auto p : prerequisites){
            int u = p[0];
            int v = p[1];
            adj[v].push_back(u);
        }

        for(int i = 0;i<numCourses;i++){
            if(vis[i] == 0 && !dfs(i,adj,vis)){
                return false;
            }
        }

        return true;


    }

    bool dfs(int n , vector<vector<int>>& adj , vector<int> &vis ){
        if(vis[n] == 1) return false;
        if(vis[n] == 2) return true;

        vis[n] = 1;
        
        for(auto it : adj[n]){
            if(!dfs(it , adj, vis)) return false;    
        }

        vis[n] = 2;
        return true;
    }
};
