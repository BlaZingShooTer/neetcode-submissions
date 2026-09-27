class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int j = 0;

        int f = 0;

        while(j < nums.size() && i< nums.size()){

            if(nums[i] != val){
                nums[j] = nums[i];
                j++;
                f++;
            }
            i++;
        }

        return j;
    }
};