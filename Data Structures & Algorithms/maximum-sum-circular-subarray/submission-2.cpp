class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int ts = 0;

        for(auto x : nums){

            ts += x;
        }

        int max_sum = nums[0];
        int cs = 0;

        for(auto x : nums){

            cs += x;

            max_sum = max(max_sum , cs);

            if(cs < 0) cs = 0;


        }

        int min_sum = nums[0];
        cs = 0;

        for(auto x : nums){

            cs += x;

            min_sum = min(min_sum , cs);

            if(cs > 0) cs = 0;


        }

        if(ts == min_sum ) return max_sum;

        return max(max_sum , ts - min_sum);

    }
};