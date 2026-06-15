#include<set>
#include<string>

class Solution {
public:
    vector<int> plusOne(vector<int>& d) {
        stack<int> st;
        vector<int> ans;
        int carr = 1;
        for(int i = d.size()-1;i>=0;i--)
        {
            d[i] = d[i] + carr;
            
            if(d[i] >= 10){
                d[i] = d[i]%10;
                st.push(d[i]);
                carr = 1;
            }
            else{
                st.push(d[i]);
                carr = 0;
            }
        }
        if(carr == 1) st.push(1);
        
        while(!st.empty()){

            ans.push_back(st.top());
            st.pop();
        }

        return ans;
        
    }
};
