class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<int> cur;
        vector<vector<int>> ans;

        sort(nums.begin(),nums.end());

        func(nums,0,ans,cur);

        return ans;

    }

    void func(vector<int> &nums, int i , vector<vector<int>> &ans , vector<int> &cur){
         if(i == nums.size()){
            ans.push_back(cur);
            return;
         }


         cur.push_back(nums[i]);
         func(nums,i+1,ans,cur);
        cur.pop_back();
         while(i+1<nums.size() && nums[i] == nums[i+1]){
            i++;
         }

         func(nums,i+1,ans,cur);


    }

    


};
