class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));

        return func(0,amount,coins,dp);
    }

    int func(int i , int tr , vector<int>& c , vector<vector<int>>& dp){
        if(i>=c.size())return 0;

        if(i == c.size()-1 && tr%c[i]==0) return 1;
        if(i == c.size()-1 && tr%c[i]!=0) return 0;



        if(dp[i][tr]!=-1)return dp[i][tr];

        int nt = func(i+1,tr,c,dp);
        int t = 0;

        if(tr >= c[i]){
            t = func(i,tr - c[i],c,dp);
        }

        return dp[i][tr] =  t+nt;
    }
};
