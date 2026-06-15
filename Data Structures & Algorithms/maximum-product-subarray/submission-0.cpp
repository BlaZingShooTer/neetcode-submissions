class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), res = nums[0];

        int p = 0, s= 0;

        for(int i = 0;i<n;i++){
            p = nums[i] * (p == 0 ? 1 : p);

            s  = nums[n - 1 - i] * ( s == 0 ? 1 : s);

            res = max(res , max(p ,s));
        }

        return res;
    }
};
