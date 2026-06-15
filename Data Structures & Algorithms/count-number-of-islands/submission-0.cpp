class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int cnt = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    cnt++;
                    dfs(vis,grid,i,j);
                }
            }
        }

        return cnt;
    }


    void dfs(vector<vector<bool>>& vis , vector<vector<char>>& grid , int i, int j){
        vis[i][j] = true;

        int n = grid.size();
        int m = grid[0].size();

        int dx[] = {-1,0,1,0};
        int dy[] = { 0 , -1,0,1};

        for(int k = 0;k<4;k++){
            int nx = dx[k] + i;
            int ny = dy[k] + j;


            if(nx < n && ny < m &&  nx>=0 && ny >=0 && grid[nx][ny] == '1' && !vis[nx][ny]){
                dfs(vis,grid,nx,ny);
            }
        } 
    }
};
