class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        int n1 = word1.size();
        int n2 = word2.size();

        int k = min(n1,n2);
        string ans = "";
        for(int i = 0;i<k;i++){
            ans+= word1[i];
            ans+=word2[i];
        }

        if(n1<n2){
            ans+= word2.substr(n1,n2-n1);
        }
        else{
            ans+= word1.substr(n2,n1-n2);
        }

        return ans;
    }
};