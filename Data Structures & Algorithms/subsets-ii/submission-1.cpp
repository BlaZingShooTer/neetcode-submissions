class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        vector<vector<int>> ans;
        vector<int> s;

        func(nums,0,s,ans);
        return ans;


    }

    void func(vector<int>& nums, int i , vector<int>& s, vector<vector<int>>& ans ){
    
        ans.push_back(s);
        for(int j = i;j<nums.size();j++){
            if(nums[j] == nums[j-1] && j>i){
                continue;
            }

            s.push_back(nums[j]);
            func(nums,j+1,s,ans);

            s.pop_back();
            
        }
    }
};
