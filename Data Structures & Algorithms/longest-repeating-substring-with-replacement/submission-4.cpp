class Solution {
public:
    int characterReplacement(string s, int k) {
        
        vector<int> f(26,0);

        int l = 0;
        int r = 0;

        int maxl = 0;
        int maxf = 0;

        while(r<s.size()){

            f[s[r] - 'A']++;

            maxf = max(maxf , f[s[r]-'A']);

            while(r-l+1 - maxf > k){
                f[s[l]-'A']--;
                l++;
            }

            maxl = max(maxl , r-l+1);
            r++;

        }

        return maxl;
        
    }
};
