class Solution {
public:
    int jump(vector<int>& nums) {

        int cnt = 0;
        int f = 0;
        int ce = 0;

        for(int i = 0;i<nums.size()-1;i++){

            f = max(f , i + nums[i]);

            if( i == ce){
                cnt++;
                ce = f;
            }

        }

        return cnt;
        
    }
};
