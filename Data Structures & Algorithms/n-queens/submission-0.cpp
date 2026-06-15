class Solution {
public:

    unordered_set<int> col;
    unordered_set<int> posDiag;
    unordered_set<int> negDiag;

    vector<vector<string>> res;

    vector<vector<string>> solveNQueens(int n) {
        
        vector<string> b(n, string(n,'.'));

        func(0,n,b);
        return res;
    }


    void func(int r , int n , vector<string> &b){
        if(r == n){
            res.push_back(b);
            return;
        }

        for(int c = 0;c < n;c++){
            if(col.count(c) || posDiag.count(r+c) || negDiag.count(r-c)){
                continue;
            }
        

        col.insert(c);
        posDiag.insert(r+c);
        negDiag.insert(r-c);
        b[r][c] = 'Q';


        func(r+1,n,b);


        col.erase(c);
        posDiag.erase(r+c);
        negDiag.erase(r-c);
        b[r][c] = '.';

    }

    }

};
