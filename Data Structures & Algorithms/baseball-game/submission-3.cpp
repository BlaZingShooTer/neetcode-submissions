class Solution {
public:
    int calPoints(vector<string>& o) {
        
        stack<int> st;

        for(int i = 0;i<o.size();i++){

            if(o[i] == "+"){

                int x1 = 0;
                int x2 = 0;

                if(!st.empty()){
                    x1 = st.top();
                    st.pop();

                    x2 = st.top();

                }

                st.push(x1);
                st.push(x1+x2);
            }

            else if(o[i] == "D"){
                if(!st.empty()){
                    int x1 = st.top();
                    
                    st.push(2*x1);
                }
            }

            else if(o[i] == "C"){

                if(!st.empty()){
                    st.pop();
                }

            }
            else{

                st.push(stoi(o[i]));
            }

        }

        int ans = 0;

        while(!st.empty()){
            ans+= st.top();
            st.pop();
        }

        return ans;
    }
};