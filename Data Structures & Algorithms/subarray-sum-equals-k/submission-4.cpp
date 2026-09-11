class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        map<int , int> mp;

        int cnt = 0;
        int sum = 0;

        mp[sum] = 1;

        for(int i = 0;i<nums.size();i++){
            sum += nums[i];

            int d = sum - k;

            
            if(mp.find(d)!= mp.end()){
                cnt+= mp[d];
            }
            

            mp[sum]++;
        }

        return cnt;
        
    }
};