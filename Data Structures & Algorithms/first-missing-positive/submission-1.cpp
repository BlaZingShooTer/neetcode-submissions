class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        set<int> st;

        for(int i = 0;i<nums.size();i++){
            
            st.insert(nums[i]);

        }

        for(int i = 1;i<=nums.size();i++){
            if(!st.count(i))return i;
             
        }

        return nums.size() + 1;
    }
};