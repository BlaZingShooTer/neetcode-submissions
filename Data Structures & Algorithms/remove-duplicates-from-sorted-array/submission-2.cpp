class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int k = 1;

        vector<int>ans;

        int prev = nums[0];
        ans.push_back(prev);
        for(int i = 1;i<nums.size();i++){
            
            int curr = nums[i];

            if(curr == prev){
                continue;
            }
            else{
                ans.push_back(curr);
                k++;
                prev = curr;
            }
        }
        nums = ans;
        return k;
    }
};