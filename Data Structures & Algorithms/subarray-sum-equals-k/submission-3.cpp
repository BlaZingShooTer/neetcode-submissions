class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;

        int cs = 0;

        map<int,int> mp;

        mp[0] = 1;

        for(int i = 0;i<nums.size(); i++){
            cs += nums[i];

            int d = cs - k;

            res += mp[d];

            mp[cs]++;
        }

        return res;
    }
};