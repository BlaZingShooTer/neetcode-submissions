class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> st;

        for (int a : ast) {
            bool destroyed = false;

            while (!st.empty() && st.top() > 0 && a < 0) {
                if (abs(st.top()) < abs(a)) {
                    st.pop();          // top dies, continue fight
                }
                else if (abs(st.top()) == abs(a)) {
                    st.pop();          // both die
                    destroyed = true;
                    break;
                }
                else {
                    destroyed = true;  // current dies
                    break;
                }
            }

            if (!destroyed) st.push(a);
        }

        vector<int> res(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            res[i] = st.top();
            st.pop();
        }

        return res;
    }
};
