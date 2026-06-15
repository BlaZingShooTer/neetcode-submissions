class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        vector<vector<int>> ans;

        int n = h.size();
        int m = h[0].size();


        vector<vector<bool>> pac(n,vector<bool>(m,false));
        vector<vector<bool>> atl(n,vector<bool>(m,false));

        for(int i=0;i<m;i++){
            if(!pac[0][i]){
                dfs(0,i,h,n,m,pac,h[0][i]);
            }

            if(!atl[n-1][i]){
                dfs(n-1,i,h,n,m,atl,h[n-1][i]);
            }
        }


        
        for(int i=0;i<n;i++){
            if(!pac[i][0]){
                dfs(i,0,h,n,m,pac,h[i][0]);
            }

            if(!atl[i][m-1]){
                dfs(i,m-1,h,n,m,atl,h[i][m-1]);
            }
        }


        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(pac[i][j] && atl[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
    
        return ans;
    }


    void dfs(int i, int j, vector<vector<int>>& h,int n,int m,vector<vector<bool>> &vis,int preval){
        if(i<0 || j<0 || i>=n || j>=m || h[i][j] < preval)return;

        vis[i][j] = true;

        vector<vector<int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};

        for(int k = 0;k<4;k++){
            int r = i + dir[k][0];
            int c = j + dir[k][1];

            if(r>=0 && r<n && c>=0 && c<m && h[r][c] >= h[i][j] && !vis[r][c]){
                dfs(r,c,h,n,m,vis,h[i][j]);
            }

        }
        
    }
};
