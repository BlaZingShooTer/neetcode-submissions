class Solution {
public:
    int countSubstrings(string s) {
        if(s.size() == 1) return 1;
        int cnt = 0;

        
        int reslen = 0;

        for(int i =0;i<s.size() ;i++){
            int l = i , r = i;

            while(l>= 0 && r < s.size() && s[l] == s[r]){
                cnt++;
                l--;
                r++;
            }

            l = i;
            r = i+1;

            while(l>= 0 && r < s.size() && s[l] == s[r]){
                cnt++;
                l--;
                r++;
            }
        }

        return cnt;
    }
};
