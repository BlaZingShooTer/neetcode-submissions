#include<string>
class Solution {
public:
    string multiply(string num1, string num2) {
        
        if( num1 == "0" || num2 == "0")return "0";

        int m = num1.size();

        int n = num2.size();

        vector<int> ans(m+n,0);

        for(int i = m-1 ; i >= 0; i-- ){

            for(int j = n-1 ; j >= 0; j-- ){
                int mul = (num1[i]-'0')*(num2[j]-'0');

                int p1 = i+j; // carry over
                int p2 = i+j+1; //ones place
                
                int sum = mul + ans[p2];

                ans[p2] = sum % 10;
                ans[p1] += sum/10;
            }
        }

        string res = "";

        for(int i = 0;i<ans.size();i++){
            if(!(res.empty() && ans[i] == 0)){
                res += ans[i] + '0';
            }
        }

        return res;
    }
};
