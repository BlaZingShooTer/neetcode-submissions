class Solution {
public:
    vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};

    
    int longestIncreasingPath(vector<vector<int>>& m) {
        
        int r = m.size();
        int c = m[0].size();

        vector<vector<int>> dp(r,vector<int>(c,-1));

        int lip = 0;

        for(int i = 0;i<r;i++){
            for(int j=0;j<c;j++){
                lip = max(lip,func(m,i,j,INT_MIN,dp));
            }
        }

        return lip;
    }

    int func(vector<vector<int>>& m , int r , int c, int preval, vector<vector<int>>& dp){

        if(r <0 || c<0 || r>=m.size() || c >= m[0].size() || m[r][c] <= preval) return 0;

        if(dp[r][c]!=-1) return dp[r][c];

        int res = 1;

        for(int i = 0;i<dir.size();i++){
            res = max(res, 1 + func(m,r + dir[i][0], c + dir[i][1], m[r][c], dp));
        }

        return dp[r][c] = res;
    }
};
