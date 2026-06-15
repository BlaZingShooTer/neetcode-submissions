class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return func(0, 0,m,n,dp,word1,word2);;
    }

    int func(int i, int j ,int m, int n , vector<vector<int>>& dp, string &w1, string &w2 ){
        if(i==m)return n -j;
        if(j == n) return m - i;

        if(dp[i][j]!= -1) return dp[i][j];

        if(w1[i] == w2[j]){
            dp[i][j] = func(i+1,j+1,m,n,dp,w1,w2);
        }
        else{
            int res = min(func(i+1,j,m,n,dp,w1,w2) , func(i,j+1,m,n,dp,w1,w2));

            res = min(res, func(i+1,j+1,m,n,dp,w1,w2));
            dp[i][j] = res + 1;
        }
        return dp[i][j];
    }
};
