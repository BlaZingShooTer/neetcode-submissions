class Solution {
public:
    int evalRPN(vector<string>& t) {
        stack<string> st;


        for(int i = 0;i<t.size();i++){

            if(t[i] == "+"){
                if(!st.empty()){
                    int x1 = stoi(st.top());
                    st.pop();
                    int x2 = stoi(st.top());
                    st.pop();

                    int x3 = x1 + x2;
                    st.push(to_string(x3));

                }
            }
            else if(t[i] == "-"){
                if(!st.empty()){
                    int x1 = stoi(st.top());
                    st.pop();
                    int x2 = stoi(st.top());
                    st.pop();

                    int x3 = x2 - x1;
                    st.push(to_string(x3));
                }
            }
            else if(t[i] == "*"){
                if(!st.empty()){
                    int x1 = stoi(st.top());
                    st.pop();
                    int x2 = stoi(st.top());
                    st.pop();

                    int x3 = x2 * x1;
                    st.push(to_string(x3));
                }
            }
            else if(t[i] == "/"){
                 if(!st.empty()){
                    int x1 = stoi(st.top());
                    st.pop();
                    int x2 = stoi(st.top());
                    st.pop();

                    int x3 = x2 / x1;
                    st.push(to_string(x3));
                }
            }

            else{
                st.push(t[i]);
            }

        }

        return stoi(st.top());


    }
};
