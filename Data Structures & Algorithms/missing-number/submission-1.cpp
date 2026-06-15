class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int s = 0;
        int ac = 0;
        int n = nums.size();

        ac = n*(n+1)/2;
        
        for(int i = 0;i<n;i++){
            s += nums[i];
        }

        if ( s == ac) return 0;

        return ac-s;
    }
};
