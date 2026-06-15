class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pr = 1;
        int zc =0;
        int n = nums.size();
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == 0) zc++;
            else{
                pr *= nums[i];
            }
        }

        if(zc > 1){
            return vector<int> (n,0);
        }

        vector<int> ans(n);

        for(int i = 0;i<nums.size();i++){
            if(zc>0){
                if(nums[i]==0){
                    ans[i] = pr;
                }
                else{
                    ans[i] = 0;
                }
            }

            else{
                ans[i] = pr/nums[i];
            }
        }
        
        return ans;
    }
};
