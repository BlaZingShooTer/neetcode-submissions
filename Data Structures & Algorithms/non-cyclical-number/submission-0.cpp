#include<bits/stdc++.h>
class Solution {
public:
    bool isHappy(int n) {
        string s = to_string(n);
        map<int,int> memory;

        while(1){
            int val = sqValue(s);
            if(val == 1) return true;

            if(memory.find(val)!=memory.end()) break;
            memory[val] =1;
            s = to_string(val);
        }
        
        return false;
    }

    int sqValue(string s){
        int sq = 0;
        for(int i = 0;i<s.size();i++){
            int s1 = s[i] - '0';

            sq += s1*s1;
        }

        return sq;

    }
};
