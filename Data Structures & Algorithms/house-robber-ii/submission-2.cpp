class Solution {
public:

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        return max(
            f(0, n - 2, nums, dp1),
            f(1, n - 1, nums, dp2)
        );
    }

    int f(int s, int e, vector<int>& nums, vector<int>& dp) {
        if (s > e)
            return 0;

        if (dp[s] != -1)
            return dp[s];

        int skip = f(s + 1, e, nums, dp);

        int take = nums[s] + f(s + 2, e, nums, dp);

        return dp[s] = max(skip, take);
    }
};