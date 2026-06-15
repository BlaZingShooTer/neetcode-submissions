class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        int mx = 1;

        sort(nums.begin(),nums.end());

        int pre = nums[0];
        int curr = 1;
        for(int i = 1;i<nums.size();i++){
            
            if(nums[i] == pre + 1){
                curr++;
                
                mx = max(mx, curr);
                
                
            }
            else if(nums[i] == pre){
                continue;
            }
            else{
                curr = 1;
            }

            pre = nums[i];
        }

        return mx;
    }
};
