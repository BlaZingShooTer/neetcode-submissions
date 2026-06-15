class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int cnt = -1;
        int f = 0;
        int n = grid.size();
        int m = grid[0].size();
       
        queue<pair<int,int>> q;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j] == 1){
                    f++;
                }
            }
        }
        if(f==0) return 0;
        
        vector<vector<int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
        while(!q.empty()){
            
            int l = q.size();

            for(int i = 0;i<l;i++){

            int x = q.front().first;
            int y =  q.front().second;
           
            q.pop();

            for(int i = 0;i<4;i++){
                int r = x + dir[i][0];
                int c = y + dir[i][1];

                if(r<n && c<m && r>=0 && c>=0 && grid[r][c]==1){
                    q.push({r,c});
                    grid[r][c] = 2;
                    f--;
                }
            }

        }

        cnt++;

    }
    
        if(f!=0) return -1;
        return cnt;
    }
};
