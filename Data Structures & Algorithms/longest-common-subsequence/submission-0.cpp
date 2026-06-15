class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        if(t1 == t2) return t1.size();
        int m = t1.size();
        int n = t2.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));

        return func(t1,t2,0,0,dp);
    }


    int func(string t1 , string t2 , int i , int j, vector<vector<int>>&dp){
        if(i== t1.size() || j == t2.size()){
            return 0;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        if(t1[i] == t2[j]){
            dp[i][j] =  1 + func(t1,t2,i+1,j+1,dp);
        }

        else{
            dp[i][j] = max(func(t1,t2,i+1,j,dp) , func(t1,t2,i,j+1,dp));
        }

        return dp[i][j];
    }
};
