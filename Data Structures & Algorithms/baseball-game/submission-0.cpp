class Solution {
public:
    int calPoints(vector<string>& o) {
        
        stack<string> st;

        for(int i = 0;i<o.size();i++){
            
            if(o[i]== "+"){

                int x1 = stoi(st.top());
                st.pop();
                int x2 = stoi(st.top());
                int x3 = x1 + x2;

                

                st.push(to_string(x1));
                st.push(to_string(x3));
                
            }

            else if(o[i] == "C"){
                st.pop();
            }

            else if(o[i] == "D"){
                int x1 = stoi(st.top());
                int x2 = 2*x1;
                st.push(to_string(x2));
                
            }
            else{
                st.push(o[i]);
            }

        }
        int val = 0;
        while(!st.empty()){
            val += stoi(st.top());
            st.pop();
        }

        return val;

    }
};