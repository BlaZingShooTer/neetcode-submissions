class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        

        vector<vector<bool>> vis(n, vector<bool>(n,false));
        priority_queue<pair<int,pair<int,int>>, 
                       vector<pair<int,pair<int,int>>>, 
                       greater<pair<int,pair<int,int>>>> minh;

        minh.push({grid[0][0],{0,0}});
        vis[0][0] = true;
        int i = 0;int j = 0;
        int t = 0;

        while(!minh.empty()){
            auto cur = minh.top();
            minh.pop();
            int t = cur.first;
            
            int r = cur.second.first;
            int c = cur.second.second;

            if(r == n-1 && c == m-1) return t;


            vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
            

            for(int i = 0;i<4;i++){
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];


                if(nr >=0 && nr < n && nc < m && nc >=0 && !vis[nr][nc]){
                    vis[nr][nc] = true;
                    minh.push({max(grid[nr][nc],t),{nr,nc}});
                }
            }

        }

        return t;
    }
};
