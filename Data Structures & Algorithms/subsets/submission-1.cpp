class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> s;
        sub(nums,0,s,ans);
        return ans;


    }

    void sub(const vector<int>& nums, int i, vector<int>& s, 
    vector<vector<int>>& ans){
        if(i>=nums.size()){
            ans.push_back(s);
            return;
        }

        s.push_back(nums[i]);
        sub(nums,i+1,s,ans);

        s.pop_back();
        sub(nums,i+1,s,ans);
    }
};
