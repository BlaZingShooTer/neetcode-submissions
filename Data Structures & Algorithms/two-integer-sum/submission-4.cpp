class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        if(nums.size() == 2) return {0,1};

        map<int,int>mp;

        for(int i = 0;i<nums.size();i++){

            int d = target - nums[i];

            cout<<d<<endl;

            if(mp.find(d)!= mp.end()){

                return {mp[d],i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};
