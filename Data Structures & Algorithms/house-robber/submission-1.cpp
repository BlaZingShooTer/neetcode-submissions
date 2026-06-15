class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec(n+1,-1);
        return func(0,vec,nums);
    }

    int func(int i, vector<int>&vec ,vector<int>& nums){
        if(i>=nums.size()) return 0;


        if(vec[i]!=-1) return vec[i];

        return vec[i] = max(func(i+1,vec,nums),func(i+2,vec,nums) + nums[i]);
    }
};
