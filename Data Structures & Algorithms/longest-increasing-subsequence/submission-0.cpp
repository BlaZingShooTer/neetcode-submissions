class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n+1, vector<int>(n+1,-1));

        return func(0,-1,nums,memo);

    }

    int func(int i , int j , vector<int> &a ,vector<vector<int>> &dp){
        if(i == a.size()){
            return 0;
        }

        if(dp[i][j+1]!=-1){
            return dp[i][j+1];
        }

        int nt = func(i+1,j,a,dp);
        int t = INT_MIN;
        if(j==-1 || a[j] < a[i] ){
            t = 1 + func(i+1,i,a,dp);
        }


        return dp[i][j+1] = max(t,nt);
    }
};
