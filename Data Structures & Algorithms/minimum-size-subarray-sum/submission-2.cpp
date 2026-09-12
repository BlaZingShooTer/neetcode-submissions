class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int size = nums.size();
        int s = accumulate(nums.begin(),nums.end(),0);
        
        if(s < target) return 0;

        int sum = 0;

        int r = 0;
        int l = 0;
        while(r<nums.size()){

            sum+= nums[r];

            while(sum >= target){
                size = min(size , r-l+1);
                sum-= nums[l];
                l++;
                
            }
            
            r++;

        }
        return size;
    }
};