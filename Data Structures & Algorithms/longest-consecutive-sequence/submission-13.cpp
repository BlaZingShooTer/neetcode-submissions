class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        if(nums.size() == 0) return 0;


        int maxcnt = 1;
        int cnt = 1;
        for(int i = 1;i<nums.size();i++){

            if(nums[i] == nums[i-1]){
                continue;
            }
            else if(nums[i] == nums[i-1]+1){
                cnt++;
            }
            else{
                cnt = 1;
                
            }
            maxcnt = max(maxcnt , cnt);
        }

        return maxcnt;
        
    }
};
