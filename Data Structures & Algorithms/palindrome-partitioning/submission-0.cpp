class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> part;
        func(s,0,part,res);
        return res;
    }

    void func(string &s , int i, vector<string> &cur , vector<vector<string>> &ans){

        if(i>=s.size()){
            ans.push_back(cur);
            return;
        }

        for(int j =i;j<s.size();j++){
            if(isPali(s,i,j)){
                cur.push_back(s.substr(i,j-i+1));
                func(s,j+1,cur,ans);
                cur.pop_back();
            }
        }
    }

    bool isPali(string s , int i , int j){
        while(i<j){
            if(s[i]!=s[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};
