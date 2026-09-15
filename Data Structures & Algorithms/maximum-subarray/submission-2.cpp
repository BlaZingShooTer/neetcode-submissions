class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int curr =  0;

        for( auto x : nums){    

            if(curr < 0) curr = 0;

            curr+= x;

            sum = max(sum , curr);
        }

        return sum;
    }
};
