class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<pair<int,int>>st;

        int ma = 0;

        for(int i = 0;i<h.size();i++){

            int strt = i;

            while(!st.empty() && st.top().second > h[i]){

                int a = ( i - st.top().first) * st.top().second;

                ma = max(ma , a);

                strt = st.top().first;
                st.pop();
                

            }
            
            st.push({strt,h[i]});

        }


      int n = h.size();
while (!st.empty()) {
    ma = max(ma, (n - st.top().first) * st.top().second);
    st.pop();
}
        return ma;
    }
};
