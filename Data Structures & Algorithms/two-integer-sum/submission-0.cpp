class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        map<int,int> mp;

        for(int i = 0;i<nums.size();i++)
        {
            int rem = target - nums[i];

            if(mp.find(rem) != mp.end())
            {
               ans = {i,mp[rem]};
            }

            mp[nums[i]] = i;
        }

         sort(ans.begin(),ans.end());
         return  ans;
    }
};
