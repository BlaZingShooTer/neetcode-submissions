class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int mA = 0;
        stack<pair<int,int>> st;

        for(int i = 0;i<heights.size();i++){
            int start = i;

            while(!st.empty() && st.top().second > heights[i]){
                pair<int,int> top = st.top();
                mA = max(mA ,(i - st.top().first)* st.top().second );
                start = st.top().first;
                st.pop();
            }
            st.push({start, heights[i]});
        }
        int n = heights.size();
        while(!st.empty()){
            mA = max(mA, st.top().second *( n- st.top().first) );
            st.pop();
        }
        return mA;
    }
};
