class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int t) {
        vector<vector<int>> ans;
        vector<int> cur;

        func(nums,t,ans,cur,0);

        return ans;
    }

    void func(vector<int>& nums , int t, vector<vector<int>> &ans ,vector<int> &cur, int i){

        if(t == 0 ) {
            ans.push_back(cur);
            return ;
        }

        if(i>=nums.size() || t <0) return;

        cur.push_back(nums[i]);
        func(nums,t-nums[i],ans,cur,i);

        cur.pop_back();
        func(nums,t,ans,cur,i+1);

    }
};
