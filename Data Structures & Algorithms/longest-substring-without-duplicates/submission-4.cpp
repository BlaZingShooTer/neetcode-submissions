class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        map<char,int> mp;
        int maxl = 0;
        int l = 0;
        int r = 0;

        while(r<n){

            if(mp.find(s[r])!= mp.end() && mp[s[r]] >= l){
                
                l = mp[s[r]] + 1;
            }
            int len = r-l+1;
            maxl = max(maxl , len);

            mp[s[r]] = r;

            r++;


        }

        return maxl;
    }
};
