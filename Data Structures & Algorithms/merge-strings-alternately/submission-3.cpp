class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int s1 = word1.size();
        int s2 = word2.size();
        string out = "";
        if(s1 == s2){

            for(int i = 0;i<s1;i++){
                out += word1[i];

                out += word2[i];
            }

            
        }

        else if (s1 > s2){

            for(int i = 0;i<s2;i++){
                out += word1[i];
                out += word2[i];
            }

            for(int i = s2;i<s1;i++){
                out += word1[i];
            }

        }

        else{

            for(int i = 0;i<s1;i++){
                out += word1[i];
                out += word2[i];
            }

            for(int i = s1;i<s2;i++){
                out += word2[i];
            }

        }

        return out;
    }
};