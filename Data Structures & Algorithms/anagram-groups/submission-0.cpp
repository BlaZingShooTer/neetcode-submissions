#include<bits/stdc++.h>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<int, bool> mp;
        for(int i = 0;i<strs.size();i++){
            if(mp[i]) continue;

            vector<string> temp;
            temp.push_back(strs[i]);
            mp[i] = true;

            for(int j = i+1;j<strs.size();j++){

                if(!mp[j] && check(strs[i] ,strs[j])){
                    temp.push_back(strs[j]);
                    mp[j] = true;
                }
            }
            ans.push_back(temp);
        }
        
        return ans;
    }


    bool check(string s1 , string s2){
        if (s1.size() != s2.size()) return false;
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
 
        return s1 == s2;
    }
};
