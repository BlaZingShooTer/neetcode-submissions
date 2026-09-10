class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string val = strs[0];

        for(int i = 0;i<strs.size();i++){
            int k = 0;
            int n = min(strs[i].size(), val.size());

            for(int j = 0;j<n;j++){
                if(val[j] == strs[i][j]){
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