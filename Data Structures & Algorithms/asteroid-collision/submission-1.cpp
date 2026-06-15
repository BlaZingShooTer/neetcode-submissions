class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int>st;

        for(int i = 0;i<ast.size();i++){

            bool dest = false;
            
            while(!st.empty() && st.top() > 0 && ast[i] < 0){

                if(abs(st.top()) < abs(ast[i])){
                    st.pop();
                }

                else if(abs(st.top()) == abs(ast[i])){
                    st.pop();
                    dest = true;
                    break;
                }
                else{
                    dest = true;
                    break;
                }

            }

            if(!dest) st.push(ast[i]);
        }

        vector<int> res(st.size());

        for(int i = st.size()-1; i>=0;i--){
            res[i] = st.top();
            st.pop();
        }


        return res;
    }
};