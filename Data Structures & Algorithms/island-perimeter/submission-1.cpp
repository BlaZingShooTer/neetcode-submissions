class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));

        int p = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]){
                    return dfs(grid,vis,i,j);
                }
            }
        }

        return 0;

        
    }


    int dfs(vector<vector<int>>& g, vector<vector<int>>& vis, int i, int j) {
    
    if (i < 0 || j < 0 || i >= g.size() || j >= g[0].size() || g[i][j] == 0) {
        return 1;
    }

    if (vis[i][j]) {
        return 0;
    }

    vis[i][j] = 1;

    vector<int> dx = {0, -1, 1, 0};
    vector<int> dy = {-1, 0, 0, 1};

    int val = 0;

    for (int l = 0; l < 4; l++) {
        val += dfs(g, vis, i + dx[l], j + dy[l]);
    }

    return val;
}
};