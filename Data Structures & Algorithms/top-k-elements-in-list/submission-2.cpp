class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        // Count frequency
        for (int x : nums) {
            mp[x]++;
        }

        // Store (value, frequency) pairs
        vector<pair<int,int>> vec;
        for (auto &it : mp) {
            vec.push_back({it.first, it.second});
        }

        // Sort by frequency (descending)
        sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        // Pick top k
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(vec[i].first);
        }

        return ans;
    }
};
