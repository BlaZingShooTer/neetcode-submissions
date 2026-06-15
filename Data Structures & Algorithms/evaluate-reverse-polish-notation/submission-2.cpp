class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(int i = 0;i<tokens.size();i++){
            
            if(!st.empty() && (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "/" || tokens[i] == "*")){
                int x1 = st.top();
                st.pop();
                int x2 = st.top();
                st.pop();

                if(tokens[i] == "+" ) x1 = x1 + x2;
                else if(tokens[i] == "-" ) x1 = x2 - x1;
                else if(tokens[i] == "/" ) x1 = x2 / x1;
                else{
                    x1 = x1 * x2;
                }
                st.push(x1);
            } 
            else{
                st.push(stoi(tokens[i]));
            }
            

            
        }

        return st.top();
    }
};
