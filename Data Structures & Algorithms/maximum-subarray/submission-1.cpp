class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int currSum = 0;
        for(int i = 0;i<nums.size();i++){
            
            if(currSum<0) currSum = 0;

            currSum+= nums[i];

            sum = max(currSum,sum);
        }
        return sum;
    }
};
