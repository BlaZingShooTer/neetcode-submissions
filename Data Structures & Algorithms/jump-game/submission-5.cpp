class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int g = 0;

        for(int i = 0;i<nums.size();i++){

            if(i > g) return false;

            g = max(g , i + nums[i]);

            
            if(g >= nums.size()-1) return true;

        }


        return true;
    }
};
