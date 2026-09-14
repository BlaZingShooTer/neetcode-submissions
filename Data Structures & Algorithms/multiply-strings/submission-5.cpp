class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 =="0") return "0";


        vector<int> ans(num1.size() + num2.size() , 0);


        for(int i = num1.size()-1 ;i>=0;i--){
            for(int j = num2.size()-1; j>=0 ;j--){

                int sum = (num1[i] - '0') * (num2[j]-'0') + ans[i+j+1];

                ans[i+j+1] = sum%10;
                ans[i+j] += sum/10;
                
            }
        }


        string ss = "";

        int r =0;
        while(r<ans.size() && ans[r] == 0){
            r++;
        }

        for(int i = r;i<ans.size();i++){

            
                ss += (ans[i] + '0');
            

        }

        return ss;

    }
};
