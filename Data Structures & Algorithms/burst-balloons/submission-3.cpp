class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));

        nums.insert(nums.begin(),1);
        nums.push_back(1);

        return func(nums,1,n,dp);
    }

    int func(vector<int>& nums, int l , int r , vector<vector<int>>& dp){
        if(l>r) return 0;

        if(dp[l][r]!= -1 ) return dp[l][r];

        dp[l][r] = 0;
        for(int i = l;i<=r;i++){
            int c = nums[l-1]*nums[i]*nums[r+1];

            c += func(nums,l,i-1,dp) + func(nums,i+1,r,dp);

            dp[l][r] = max(dp[l][r], c);
        }

        return dp[l][r];

    }
};
