class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int s1 = 0;
        int n = nums.size();

        for(int i = 0;i<n;i++){
            s1 = nums[i] + s1;
        }

        int s2 = (n*(n+1))/2;

        return s2 - s1;
    }
};
