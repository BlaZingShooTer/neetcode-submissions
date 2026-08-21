class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prereq, vector<vector<int>>& q) {
        vector<bool> ans(q.size(),false);
        
        
        vector<vector<int>> adj(numCourses);

        for(int i = 0;i<prereq.size();i++){
            adj[prereq[i][0]].push_back(prereq[i][1]);
        }

        for(int i = 0;i< q.size();i++){
            int x = q[i][0];
            int y = q[i][1];

            vector<int> vis(numCourses, 0);

            if(dfs(x,y,adj,vis)){
                ans[i] = true;
            }
        
        }

        return ans;

    }

    bool dfs(int s , int t, vector<vector<int>>& adj , vector<int> &vis){
        if(s == t) return true;

        if(vis[s]) return false;

        vis[s] = 1;

        for(auto it : adj[s]){
            if(dfs(it,t,adj, vis)) return true;
        }

        return false;
    }
};