class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        vector<vector<int>> dp(coins.size() +1 ,vector<int>(amount +1, -1 ));

        int ans  = func(coins.size()-1 , amount , coins , dp);
        if(ans >= 1e9) return -1;

        return ans;
    }


    int func(int i , int tr , vector<int> &coins , vector<vector<int>> &dp){
        if( i == 0){
            if(tr % coins[i] == 0) return tr /coins[i];
            return 1e9;
        }

        if(dp[i][tr]!= -1) return dp[i][tr];
        int nt = func(i-1,tr,coins , dp);
        int t = 1e9;

        if(tr >= coins[i]){
            t  =  1 + func(i,tr - coins[i] , coins , dp);
        }


        return dp[i][tr] = min(t,nt);

    }
};
 