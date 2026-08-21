class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> ans;
        for(int i=0; i<tokens.size(); i++){
            if(tokens[i] == "+"){
                int k = ans.top();
                ans.pop();

                int m = ans.top();
                ans.pop();
                ans.push(k+m);
            }
            else if(tokens[i] == "*"){
                int k = ans.top();
                ans.pop();

                int m = ans.top();
                ans.pop();
                ans.push(k*m);
            }
            else if(tokens[i] == "-"){
                int k = ans.top();
                ans.pop();

                int m = ans.top();
                ans.pop();
                ans.push(m-k);
            }
            else if(tokens[i] == "/"){
                int k = ans.top();
                ans.pop();

                int m = ans.top();
                ans.pop();
                ans.push(m/k);
            }
            else{
                ans.push(stoi(tokens[i]));
            }

        }
        return ans.top();
    }
};
