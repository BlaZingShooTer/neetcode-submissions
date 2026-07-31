class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();

        int l =0;
        int r =0;

        string ans = "";

        while(l<n1 && r<n2){
            ans += word1[l];
            ans += word2[r];

            l++;
            r++;
        }

        while(r<n2){
            ans+= word2[r];
            r++;
        }

        while(l<n1){
            ans+= word1[l];
            l++;
        }

        return ans;
    }
};