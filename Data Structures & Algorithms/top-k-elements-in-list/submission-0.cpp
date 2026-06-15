class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int,int> mp;

        for(int i = 0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }

        vector<pair<int,int>> temp;

        for(auto it : mp)
        {
            temp.push_back({it.first, it.second});
        }

        sort(temp.begin(), temp.end(), [](auto &a, auto &b) {
            return a.second > b.second; 
        });

        vector<int> ans;

        for(auto &it : temp)
        {
            if(k==0) break;

            ans.push_back(it.first);

            k--;
        }
        
        return ans;

    }
};
