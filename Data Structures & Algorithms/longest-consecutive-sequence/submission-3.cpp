class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(),nums.end());

        int cnt = 1;
        int maxlen = 1;
        for(int i = 1;i<nums.size();i++)
        {
            if(nums[i] == nums[i-1] +1 )
            {
                cnt++;
            }

            else if(nums[i]!= nums[i-1]) cnt = 1;

            else
            {
                continue;
            }

            maxlen = max(maxlen, cnt);


        }

        return maxlen;
    }
};
