class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        set<vector<int>> ans;
        vector<int> cur;
        sort(c.begin(),c.end());
        func(ans,c,0,t,cur);
        vector<vector<int>> res(ans.begin(),ans.end());
        return res;
    }


    void func(set<vector<int>> &ans, vector<int>& c, int i, int t, vector<int> &cur){

        if(t == 0){
            ans.insert(cur);
            return;
        }


        if(t < 0 || i >= c.size()){
            return;
        }


        cur.push_back(c[i]);
        func(ans,c,i+1,t-c[i],cur);

        cur.pop_back();

        while (i + 1 < c.size() && c[i] == c[i + 1]) {
            i++;
        }

        func(ans,c,i+1,t,cur);
    }
};
