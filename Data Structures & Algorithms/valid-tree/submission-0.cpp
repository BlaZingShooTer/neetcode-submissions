class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() > n-1 ) return false;
        vector<vector<int>> adj(n);
        set<int> vis; 

        for(int i = 0;i<edges.size();i++){
            int x = edges[i][0];
            int y = edges[i][1];

            adj[x].push_back(y);
            adj[y].push_back(x);

        }


        
            if(!dfs(0,-1,vis,adj)){
                return false;
            }
        

        return vis.size() == n;

    }

    bool dfs(int i ,int p, set<int> &vis , vector<vector<int>> & adj){
        
        if(vis.count(i)) return false;
        vis.insert(i);
        for(int k : adj[i]){
            if(k == p) continue;

            if(!dfs(k,i,vis,adj)) return false;
        }

        return true;
    }
};
