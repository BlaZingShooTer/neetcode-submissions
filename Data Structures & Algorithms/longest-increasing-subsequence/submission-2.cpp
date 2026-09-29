class Solution {
public:

    int func(int i, int prev,
             vector<int>& nums,
             vector<vector<int>>& dp) {

        // No elements left
        if(i == nums.size()) {
            return 0;
        }

        if(dp[i][prev + 1] != -1) {
            return dp[i][prev + 1];
        }

        // Don't take nums[i]
        int not_take = func(i + 1, prev, nums, dp);

        // Take nums[i]
        int take = 0;

        if(prev == -1 || nums[prev] < nums[i]) {
            take = 1 + func(i + 1, i, nums, dp);
        }

        return dp[i][prev + 1] = max(take, not_take);
    }


    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        if(n == 0)
            return 0;

        vector<vector<int>> dp(
            n,
            vector<int>(n + 1, -1)
        );

        return func(0, -1, nums, dp);
    }
};