class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;

        map<char,int> mp;

        for(int i = 0;i<s1.size();i++){
            mp[s1[i]]++;
        }
        int l = 0;
        int r = s1.size()-1;
        while(r<s2.size()){
            map<char,int> mp2;

            for(int i = l;i<=r;i++){
                mp2[s2[i]]++;
            }

            if(mp2 == mp) return true;

            l++;
            r++;
        }

        return false;

    }
};
