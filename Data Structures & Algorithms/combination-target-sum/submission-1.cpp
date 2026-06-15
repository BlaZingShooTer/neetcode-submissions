class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>s;

        func(nums,ans,0,target,s);

        return ans;

    }

    void func(const vector<int>& nums , vector<vector<int>>& ans , int i , int t ,vector<int>& s){
        if(t== 0){
            ans.push_back(s);
            return;
        }

        if(t<0 || i>=nums.size()){
            
            return;
        }


            s.push_back(nums[i]);
            func(nums,ans,i,t - nums[i],s);
            s.pop_back();
        
        
            func(nums,ans,i+1,t,s);
        

    }
};
