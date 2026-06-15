class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();


        queue<pair<int,int>> q;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }

        vector<vector<int>> dir = {{-1,0} , {1,0} , {0,-1} , {0,1}};

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;

            q.pop();

            for(int i = 0;i<4;i++){
                int r = x + dir[i][0];
                int c = y + dir[i][1];


                if(r>=n || r<0 || c>=m || c<0 || grid[r][c]!=INT_MAX){
                    continue;
                }

                grid[r][c] = grid[x][y] + 1;
                q.push({r,c});

            }
        }
    }


    
};
