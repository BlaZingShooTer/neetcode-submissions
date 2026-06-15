class Solution {
public:
    vector<int> vec;
    int rob(vector<int>& nums) {
        vec.resize(nums.size()+1,-1);
        return func(0, nums);
    }



    int func(int n , vector<int>&nums){
        if(n>=nums.size()){
            return 0;
        }

        if(vec[n]!= -1) return vec[n];

        int t = nums[n] +  func(n+2,nums);
        int nt = func(n+1,nums);

        return vec[n] = max(t,nt);
    }
};
