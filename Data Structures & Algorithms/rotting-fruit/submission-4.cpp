class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        int r = grid.size();
        int c = grid[0].size();
        int t = 0;
        
        queue<pair<int,int>> q;

        // Count fresh & push rotten
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j] == 2)
                    q.push({i,j});
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }

        if(fresh == 0) return 0;

        vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};

        while(!q.empty() && fresh > 0){
            int size = q.size();   // 👈 process one level
            t++;

            for(int i = 0; i < size; i++){
                auto [x,y] = q.front();
                q.pop();

                for(auto d : dir){
                    int nr = x + d[0];
                    int nc = y + d[1];

                    if(nr < 0 || nc < 0 || 
                       nr >= r || nc >= c || 
                       grid[nr][nc] != 1)
                        continue;

                    grid[nr][nc] = 2;
                    fresh--;
                    q.push({nr,nc});
                }
            }
        }

        return (fresh == 0) ? t : -1;
    }
};