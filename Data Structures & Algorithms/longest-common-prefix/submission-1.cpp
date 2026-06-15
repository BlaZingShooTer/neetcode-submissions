class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       
       
        string val = strs[0];
        for(int i = 1;i<strs.size();i++){
            int k =0;
            int n = min(val.size(), strs[i].size());
            string val2 = strs[i];
            for(int j = 0;j<n;j++){
                if(val[j] == val2[j]){
                    k++;
                }
                else{
                    break;
                }
            }
            val = val.substr(0,k);
        }

        return val;   
    }
};