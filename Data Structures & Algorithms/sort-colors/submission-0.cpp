class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r = 0;
        int w = 0;
        int b = 0;
        int n = nums.size();
        for(int i =0;i<nums.size();i++){
            if(nums[i] == 0) r++;
            else if(nums[i] == 1) w++;
            else{ b++;}

        }

        for(int i = 0;i<n;i++){
            if(r!=0) {
                nums[i] = 0;
                r--;
                }
            else if(w!=0){
                nums[i] = 1;
                w--;
            }
            else{
                nums[i] = 2;
                b--;
            }
        }


    }
};