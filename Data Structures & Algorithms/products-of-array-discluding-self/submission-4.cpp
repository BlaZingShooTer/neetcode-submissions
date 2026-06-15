class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pre = 1;
        int zc = 0;
        int n = nums.size();
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == 0) zc++;
            else{
                pre *= nums[i];
            }
            
        }

        vector<int> ans(n,0);

        if(zc>1){
            return ans;
        }

        for(int i = 0;i<nums.size();i++){
            if(nums[i] == 0){
                ans[i] = pre;
            }
            else if(zc==1 && nums[i]!=0){
                ans[i] = 0;
            }
            else{
                ans[i] = pre/nums[i];
            }
            
        }

        return ans;

    }
};
