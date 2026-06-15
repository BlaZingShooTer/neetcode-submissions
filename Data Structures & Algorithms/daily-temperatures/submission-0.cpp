class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> ans(temp.size(),0);
        stack<pair<int,int>> st;
        int day = 0;
        for(int i = 0;i<temp.size();i++){
            
            while(!st.empty() && temp[i] > st.top().first){
                auto p = st.top();
                st.pop();
                ans[p.second] = i - p.second;
            }

            

            st.push({temp[i],i});



        }

        return ans;
    }
};
