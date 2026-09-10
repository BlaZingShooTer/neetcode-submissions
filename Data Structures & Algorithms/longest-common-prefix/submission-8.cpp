class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

       if(strs.size() == 1) return strs[0];
        
        string ans = "";

        string temp = strs[0];

        for(int i =1;i<strs.size();i++){

            string w = strs[i];
            for(int j = 0;j<temp.size();j++){
                if(temp.substr(0,j+1) == w.substr(0, j+1)){
                    ans = temp.substr(0,j+1);
                }
                else{
                    if(j == 0){
                        return "";
                    }
                }
                
            }

            temp = ans;
            

        }

        return ans;


    }
};