class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));

        int ans = INT_MIN;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                ans = max(ans, f(i,j,INT_MIN,dp , matrix));
            }
        }

        return ans;
    }


    int f(int i , int j ,int prev ,vector<vector<int>> &dp ,vector<vector<int>> &m ){

        if(i<0 || j<0 || j>= m[0].size() || i>= m.size() || m[i][j] <= prev){
            return 0;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        int t = 1;

        int dx[4] = {0,1,-1,0};
        int dy[4] = {1,0,0,-1};

        for(int k = 0;k<4;k++){
            t = max(t, 1+ f(i+dx[k] , j + dy[k] , m[i][j] , dp , m));
        }

        return dp[i][j] = t;
    }
};
