class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> s;

        func(nums,s,ans,0);
        return ans;
    }

    void func(vector<int> &nums , vector<int> &sub , vector<vector<int>> &ans , int i){
        if( i == nums.size()){
            ans.push_back(sub);
            return;
        }

        sub.push_back(nums[i]);

        func(nums , sub , ans , i +1);

        sub.pop_back();

        func(nums , sub , ans , i+1 );
    }
};
