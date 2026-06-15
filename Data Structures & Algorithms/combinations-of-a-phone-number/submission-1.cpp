class Solution {
public:

    vector<string> res;
    vector<string> dc = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> letterCombinations(string d) {
        if(d.empty()) return res;
        string cur = "";
        func(0,cur, d);
        return res;

    }

    void func(int i , string &cur , string &d){
        if(cur.size() == d.size()){
            res.push_back(cur);
            return ;
        }

        string chars = dc[d[i]-'0'];
        for(char c : chars){
            cur.push_back(c);
            func(i+1,cur,d);
            cur.pop_back();
        }
    }
};
