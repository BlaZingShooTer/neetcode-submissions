class Solution {
public:
    vector<int> vec;
    vector<int> vec1;

    int rob(vector<int>& nums) {
        vec.resize(nums.size()+1,-1);
        vec1.resize(nums.size()+1,-1);

        if (nums.size() == 1) return nums[0];

        return max(func1(1,nums) , func2(0,nums));

    }

    int func1(int n , vector<int>&nums){
        if(n>=nums.size()){
            return 0;
        }

        if(vec1[n]!= -1) return vec1[n];

        int t = nums[n] +  func1(n+2,nums);
        int nt = func1(n+1,nums);

        return vec1[n] = max(t,nt);
    }

    int func2(int n , vector<int>&nums){
        if(n>=nums.size()-1){
            return 0;
        }

        if(vec[n]!= -1) return vec[n];

        int t = nums[n] +  func2(n+2,nums);
        int nt = func2(n+1,nums);

        return vec[n] = max(t,nt);
    }
};
