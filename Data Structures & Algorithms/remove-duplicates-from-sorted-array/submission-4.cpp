class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        set<int>st;

        for(int i = 0;i<nums.size();i++){
            st.insert(nums[i]);

        }
        vector<int> temp(st.begin(),st.end());
        nums = temp;
        return nums.size();
    }
};