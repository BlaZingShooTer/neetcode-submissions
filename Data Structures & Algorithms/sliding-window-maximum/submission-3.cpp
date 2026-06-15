class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;

        int l = 0;
        int r = k-1;

        while(r<nums.size()){
            vector<int> temp;
            for(int i = l;i<=r;i++){
                temp.push_back(nums[i]);
            }
            int val = *max_element(temp.begin(), temp.end());
            ans.push_back(val);
            temp.clear();
            l++;
            r++;
        }

        return ans;
    }
};
