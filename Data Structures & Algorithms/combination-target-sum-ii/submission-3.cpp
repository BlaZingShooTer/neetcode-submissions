class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> s;
        
        sort(candidates.begin(), candidates.end());
        
        func(candidates, ans, 0, target, s);
        
        return ans;
    }

    void func(vector<int>& nums,
              vector<vector<int>>& ans,
              int start,
              int target,
              vector<int>& s) {

        if (target == 0) {
            ans.push_back(s);
            return;
        }

        for (int i = start; i < nums.size(); i++) {

            if (i > start && nums[i] == nums[i-1])
                continue;

            if (nums[i] > target)
                break;

            s.push_back(nums[i]);
            func(nums, ans, i + 1, target - nums[i], s);
            s.pop_back();
        }
    }
};
