class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zc = 0;

        for(int i = 0;i<nums.size();i++){
            if(nums[i] == 0)zc++;
        }

        int n = nums.size();
        vector<int> ans(n,0);

        if(zc > 1){
            return ans;
        }

        int prod = 1;

        for(int i = 0;i<n;i++){
            if(nums[i] !=0){
                prod = prod * nums[i];
            }
            
        }

        for(int i = 0;i<n;i++){
            if(nums[i] ==0 && zc == 1){
                ans[i] = prod;
            }
            else if(nums[i] != 0 && zc ==0){
                ans[i] = prod / nums[i] ;
            }
        }

        return ans;
    }
};
