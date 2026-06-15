class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        map<char,int> mp;

        int l = 0;
        int r = 0;
        int len = 0;
        while(r < s.size()){
            if(mp.find(s[r])!= mp.end()){
                l = max(mp[s[r]]+1 , l);
            }

            mp[s[r]] = r;

            len = max(len,r-l+1);

            r++;
        }

        return len;

    }
};
