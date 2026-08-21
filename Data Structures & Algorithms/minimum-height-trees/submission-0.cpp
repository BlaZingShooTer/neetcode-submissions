class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edge) {
        vector<vector<int>> adj(n);

        for(int i = 0;i<edge.size();i++){
            int x = edge[i][0];
            int y = edge[i][1];

            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int mh = n;
        vector<int> res;

        for(int i = 0;i<n;i++){
            
            int ch = dfs(i,-1,adj);
            if(ch == mh) res.push_back(i);

            else if(ch < mh){
                mh = ch;
                res = {i};
            }
        }

        return res;
    }


    int dfs(int node, int p , vector<vector<int>> &adj){
        int h = 0;
        for(int n : adj[node]){
            if(n == p) continue;

            h = max(h ,1 + dfs(n,node,adj));
        }

        return h;
    }
};