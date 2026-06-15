class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int> mp;

        for(int i  = 0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        int k = nums.size()/3;

        vector<int> ans;

        for( auto it : mp){

            if(it.second > k) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};