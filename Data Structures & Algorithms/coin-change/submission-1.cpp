class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        vector<vector<int>> dp(coins.size() +1 ,vector<int>(amount +1, -1 ));

        int ans  = f(coins.size()-1 , amount , coins , dp);
        if(ans >= 1e9) return -1;


        return ans;
        
    }

    int f(int i , int t , vector<int> &coins , vector<vector<int>> &dp){
        if(i == 0){
            if(t%coins[i] == 0) return t/coins[i];

            return 1e9;
        } 


        if(dp[i][t]!= -1) return dp[i][t];

        int nt = f(i-1,t,coins,dp);
        int r = 1e9;
        if(t >= coins[i]){
            r = 1 + f(i,t-coins[i],coins,dp);
        }

        return dp[i][t] = min(r,nt);


    }
};
