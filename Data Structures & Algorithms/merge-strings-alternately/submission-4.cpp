class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();

        int n = min(n1,n2);
        string s = "";
        for(int i = 0;i<n;i++){
            s+= word1[i];
            s+= word2[i];
        }

        if(n1>n2){
            for(int i = n2;i<n1;i++){
                s+= word1[i];
            }
        }
        if(n1<n2){
            for(int i = n1;i<n2;i++){
                s+= word2[i];
            }
        }

        return s;
        
        
    }
};