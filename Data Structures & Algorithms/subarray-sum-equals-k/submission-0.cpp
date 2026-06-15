class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        int cS =0;
        map<int, int> mp;
        mp[0] = 1;

        for(int i =0;i<nums.size();i++){
            cS += nums[i];

            int d = cS - k;

            res+= mp[d];

            mp[cS]++;
        }

        return res;
    }
};