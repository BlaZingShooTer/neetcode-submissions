class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));

        return func(0,true,prices,dp);

    }


    int func(int i, bool buy , vector<int>& p , vector<vector<int>>& dp){
        if(i>=p.size()){
            return 0;
        }
        int bI = 0;
        if(buy){
            bI = 1;
        }
        else{
            bI = 0;
        }

        if (dp[i][bI] != -1) {
            return dp[i][bI];
        }

        int cool = func(i+1,buy,p,dp);



        if(buy){
            int buy = func(i + 1, false, p, dp) - p[i];
            return dp[i][bI] = max(buy,cool);
        }
        else{
            int sell = func(i + 2, true, p, dp) + p[i];
            return dp[i][bI] = max(sell,cool);

        }
    }
};
