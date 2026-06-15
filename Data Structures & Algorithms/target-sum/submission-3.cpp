class Solution {
public:
    int stotal = 0;
    int findTargetSumWays(vector<int>& nums, int target) {
        stotal = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(2 * stotal+1,INT_MIN));
        
        return func(0,target,0,nums,dp);
    }


    int func(int i, int tr ,int total, vector<int> &n,  vector<vector<int>>& dp){
        if(i == n.size()){
            return tr == total;
        }

        if(dp[i][total + stotal]!= INT_MIN) return dp[i][total+ stotal];

        int t = func(i+1,tr,total+n[i],n,dp) + func(i+1,tr,total - n[i],n,dp);

        return dp[i][total + stotal] = t;
    }
};
