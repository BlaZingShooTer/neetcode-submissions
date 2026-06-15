class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        queue<pair<int,int>> q;

        for(int i = 0;i<r;i++){
            for(int j = 0;j<c;j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }

        vector<vector<int>> dir = {{-1,0} , {1,0} , {0,-1} , {0,1}};

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;

            q.pop();

            for(int i =0;i<4;i++){
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];

                if(nx>=r || ny >= c || nx <0 || ny <0|| grid[nx][ny] != INT_MAX){
                    continue;
                }

                grid[nx][ny] = grid[x][y] + 1;
                q.push({nx,ny});
            }

        }
    }
};
