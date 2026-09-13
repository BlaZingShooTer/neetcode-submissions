class Solution {
public:
    string decodeString(string s) {
        string ans = "";

        stack<string> st;

        for(auto c : s){

            if(c == ']'){

                string temp = "";
                while(!st.empty() && st.top()!= "["){
                    temp= st.top() + temp;
                    st.pop();
                }

                

                st.pop();

                string count = "";
                while(!st.empty() && !st.top().empty() && isdigit(st.top()[0]))             {
                    count = st.top() + count;
                    st.pop();
                }
               
                int f = stoi(count);

                string build = "";
                for(int i = 0;i<f;i++){
                    build += temp;
                }

                st.push(build);

            }

            else{
                st.push(string(1,c));
            }


        }


        while(!st.empty()){

            ans = st.top()+ ans;
            st.pop();

        }



        return ans;
    }
};