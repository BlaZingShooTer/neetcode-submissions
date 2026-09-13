class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        

        stack<int> st;

        for(int i = 0;i<ast.size();i++){
            bool dest = false;
            while(!st.empty() && (st.top() > 0 && ast[i] < 0)) {

               int top = st.top();
               
                if(abs(ast[i]) > top){
                    dest = false;
                    st.pop();
                }
                else if(abs(ast[i]) < top){
                    dest = true;
                    break;
                }
                else{
                    dest = true;
                    st.pop();
                    break;
                }
            }

            
            if(!dest){
                    st.push(ast[i]);
            }

        }


        vector<int> ans;

        while(!st.empty()){

            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;

    }
};