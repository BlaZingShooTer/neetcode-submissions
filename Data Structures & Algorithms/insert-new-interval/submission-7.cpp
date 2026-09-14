class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {  
        intervals.push_back(newInterval);

        sort(intervals.begin(), intervals.end());
        

    

        vector<vector<int>> ans;

        ans.push_back(intervals[0]);

        for(int i = 1;i<intervals.size();i++){

            int x = ans.back()[0];
            int y = ans.back()[1];

            int x1 = intervals[i][0];
            int y1 = intervals[i][1];

            if(x1 <= y){
                int newx = min(x,x1);
                int newy = max(y,y1);

                ans.pop_back();
                ans.push_back({newx,newy});
            }
            else{

                ans.push_back(intervals[i]);
            }

        }

        return ans;
        
    }
};
