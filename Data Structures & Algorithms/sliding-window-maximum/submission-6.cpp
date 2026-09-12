class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;

        int l = 0;

        vector<int> ans;

        for(int r = 0;r<nums.size();r++){

            pq.push({nums[r], r});  
            
            if(r>=k-1){

                while(pq.top().second <= r-k || pq.top().first < nums[r]){
                    pq.pop();
                }

            ans.push_back(pq.top().first);
            }

        }

        return ans;
    }
};
