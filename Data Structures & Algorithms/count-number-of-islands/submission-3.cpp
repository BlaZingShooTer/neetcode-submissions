class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int n = 0;
    
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j] == '1'){
                    n++;                 // ✅ count new island
                    dfs(grid , i , j);   // mark entire island
                }
            }
        }
        return n;
    }

    void dfs(vector<vector<char>>& grid , int r, int c){
        if(r < 0 || c < 0 || 
           r >= grid.size() || 
           c >= grid[0].size() || 
           grid[r][c] == '0') return;

        grid[r][c] = '0';

        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};

        for(int i = 0; i < 4; i++){
            dfs(grid , r + dx[i] , c + dy[i]);
        }
    }
};