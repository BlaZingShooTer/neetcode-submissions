#include <stack>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<string> st;

        for (char &c : s) {
            if (c != ']') {
                st.push(string(1, c));
            } 
            else {
                string substr = "";

                // build string until '['
                while (!st.empty() && st.top() != "[") {
                    substr = st.top() + substr;
                    st.pop();
                }
                st.pop();  // remove '['

                // now get the number
                string k = "";
                while (!st.empty() && isdigit(st.top()[0])) {
                    k = st.top() + k;
                    st.pop();
                }

                int repeatCount = stoi(k);

                string repeated = "";
                for (int i = 0; i < repeatCount; ++i) {
                    repeated += substr;
                }

                st.push(repeated);
            }
        }

        string res = "";
        while (!st.empty()) {
            res = st.top() + res;
            st.pop();
        }

        return res;
    }
};
