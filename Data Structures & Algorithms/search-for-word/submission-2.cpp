class Solution {
public:
    bool exist(vector<vector<char>>& b, string word) {
        int n = b.size();
        int m = b[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for(int i = 0;i<n;i++){
            for(int j =0;j<m;j++){
                if(dfs(b,word,i,j,0,vis)){
                    return true;
                }
            }
        }

        return false;

    }

    bool dfs(vector<vector<char>>& b  , string w  , int r, int c, int i,vector<vector<bool>>& vis ){

        if( i == w.size()){
            return true;
        }

        if(r< 0 || c < 0 || r>=b.size() || c >= b[0].size() || b[r][c]!= w[i] || vis[r][c]) return false;

        vis[r][c] = true;

        bool res = dfs(b,w,r+1,c,i+1,vis) || dfs(b,w,r-1,c,i+1,vis) ||dfs(b,w,r,c+1,i+1,vis) ||dfs(b,w,r,c-1,i+1,vis);

        vis[r][c] = false;

        return res;
    }
};
