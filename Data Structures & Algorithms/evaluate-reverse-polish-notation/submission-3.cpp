class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(int i  = 0;i<tokens.size();i++){

            if(tokens[i] == "+"){

                if(!st.empty()){

                    int x1 = st.top(); st.pop();
                    int x2 = st.top(); st.pop();

                    x2 = x2 + x1;

                    st.push(x2);
                }
            }
            else if(tokens[i] == "-"){
                if(!st.empty()){

                    int x1 = st.top(); st.pop();
                    int x2 = st.top(); st.pop();

                    x2 = x2 - x1;

                    st.push(x2);
                }
            }

            else if(tokens[i] == "*"){
                if(!st.empty()){

                    int x1 = st.top(); st.pop();
                    int x2 = st.top(); st.pop();

                    x2 = x2*x1;

                    st.push(x2);
                }
            }
            else if(tokens[i] == "/"){
                if(!st.empty()){

                    int x1 = st.top(); st.pop();
                    int x2 = st.top(); st.pop();

                    x2 = x2/x1;

                    st.push(x2);
                }
            }
            else{
                st.push(stoi(tokens[i]));
            }


        }

        return st.top();
    }
};
