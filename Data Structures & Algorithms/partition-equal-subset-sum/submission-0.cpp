class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0;i<nums.size();i++){
            sum += nums[i];
        }

        if(sum%2 != 0) return false;
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>((sum/2) + 1 , -1));
        return func(0,sum/2,nums,dp);
    }


    bool func(int i , int tr , vector<int>& n , vector<vector<int>> &dp ){
        if(i == n.size()){
            return tr == 0;
        }

        if( tr < 0 ){return false;}

        if(dp[i][tr]!= -1) return dp[i][tr];

        bool nt = func(i+1,tr,n,dp);
        bool t = func(i+1,tr - n[i],n,dp);

        return dp[i][tr] = t || nt;
    }


};
