class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int f = 0;

        vector<int>ans;

        for(int i = 0;i<nums.size();i++){
            if(val == nums[i]){
                f++;
            }
            else{
                ans.push_back(nums[i]);
            }
        }

        nums = ans;

        return nums.size();

        
    }
};