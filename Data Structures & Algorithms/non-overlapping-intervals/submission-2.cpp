class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int cnt = 0;

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        ans.push_back(intervals[0]);

        for(int i = 1 ; i<intervals.size(); i++){

            if(ans.back()[1] > intervals[i][0]){
                cnt++;

                if(intervals[i][1] < ans.back()[1])
                    ans.back() = intervals[i];
            }
            
            else{
                ans.push_back(intervals[i]);
            }

        }

        return cnt;
    }
};
