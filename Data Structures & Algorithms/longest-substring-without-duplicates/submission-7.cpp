class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;

        int l = 0;
        int r = 0;

        map<char,int> mp;

        while(r<s.size()){
        
        if(mp.count(s[r])){

            l = max(l ,mp[s[r]] +1); // this make sure the l is within the window 
           
        }
        

        mp[s[r]] = r;

        ans = max(r-l+1 , ans);

        r++;


        }

        return ans;
    }
};
