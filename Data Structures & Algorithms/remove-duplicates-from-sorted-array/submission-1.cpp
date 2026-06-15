class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        vector<int> ans;
        int prevel = nums[0];
        
        for(int i = 1;i<nums.size();i++){
            if(prevel!= nums[i]){
                ans.push_back(prevel);
                prevel = nums[i];
                
                }
        }
        ans.push_back(nums[nums.size()-1]);
        nums = ans;
        return nums.size();
        
    }
};