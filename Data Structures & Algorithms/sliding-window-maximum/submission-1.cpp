class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l = 0;
        int r = k-1;

        vector<int> ans;
        while(r<nums.size()){

            vector<int> temp;

            for(int i = l;i<=r;i++){
                temp.push_back(nums[i]);
            }

            ans.push_back(*max_element(temp.begin(),temp.end()));
            temp.clear();
            l++;
            r++;
            

        }

        return ans;
    }
};
