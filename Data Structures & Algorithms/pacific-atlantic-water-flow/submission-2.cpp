class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        
        int r = h.size();
        int c = h[0].size();

        vector<vector<bool>> pac(r,vector<bool>(c,false));
        vector<vector<bool>> atl(r,vector<bool>(c,false));

        for(int i = 0;i<c;i++){
            dfs(0,i,pac,h);
            dfs(r-1,i,atl,h);
        }

    
        for(int i = 0;i<r;i++){
            dfs(i,0,pac,h);
            dfs(i,c-1,atl,h);
        }

        vector<vector<int>> res;

        for(int i = 0;i<r;i++){
            for(int j = 0;j<c;j++){
                if(pac[i][j] && atl[i][j]){
                    res.push_back({i,j});
                }
            }
        }

        return res;

    }


    void dfs(int i , int j, vector<vector<bool>> &o , vector<vector<int>>& h){
        o[i][j] = true;

        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};

        for(int k = 0;k<4;k++){
            int nr = i + dx[k];
            int nc = j + dy[k];

            if(nr>=0 && nc >=0 && nr < h.size() && nc < h[0].size()&& !o[nr][nc] && h[nr][nc] >= h[i][j]){
                dfs(nr ,nc , o,h);
            }
        }

    }
};
