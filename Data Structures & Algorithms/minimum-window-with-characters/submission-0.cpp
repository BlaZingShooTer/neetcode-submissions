class Solution {
public:
    string minWindow(string s, string t) {
        if(t == "") return "";
        if(s.size() < t.size()) return "";


        unordered_map<char,int> countT,window;
        for(char c : t){
            countT[c]++;
        }

        int hv = 0;
        int need = countT.size();
        pair<int,int> res = {-1,-1};
        int resLen =INT_MAX;
        int l = 0;


        for(int r = 0;r<s.size();r++ ){
            char c = s[r];

            window[c]++;

            if(countT.count(c) &&window[c] == countT[c]){
                hv++;
            }

            while(hv == need){
                if((r-l+1) < resLen){
                    resLen = r-l+1;
                    res = {l,r};
                }

                window[s[l]]--;

                if(countT.count(s[l]) && window[s[l]] < countT[s[l]]){
                    hv--;
                } 
                l++;
            }
        }

        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);


        


    }
};
