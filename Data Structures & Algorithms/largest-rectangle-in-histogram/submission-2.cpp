class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> st;
        int ma = 0;
        for(int i = 0;i<heights.size();i++){
            int start = i;

            while(!st.empty() && st.top().second > heights[i] ){
                pair<int,int> top = st.top();

                ma = max(ma, (i-st.top().first)*st.top().second);
                start  = st.top().first;
                st.pop();
            }

            st.push({start,heights[i]});
        }

        int n = heights.size();
        while(!st.empty()){
            ma = max(ma, st.top().second *( n- st.top().first) );
            st.pop();
        }

        return ma;
    }
};
