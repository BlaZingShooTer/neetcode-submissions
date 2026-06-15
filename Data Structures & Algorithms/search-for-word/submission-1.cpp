class Solution {
    
public:
    bool exist(vector<vector<char>>& b, string word) {
        
        int r = b.size();
        int c = b[0].size();
        vector<vector<int>> path(r,vector<int>(c,0));
        for(int i = 0;i<r;i++){
            for(int j =0;j<c;j++){
                if(dfs(b,word,i,j,0,path)){
                    return true;
                }
            }
        }

        return false;

    }

    bool dfs(vector<vector<char>>& b , string w, int r, int c,int i, vector<vector<int>> &path){
        if(i==w.size()){
            return true;
        }

        if(r < 0 || c <0 || r >= b.size() || c >= b[0].size() || b[r][c]!= w[i] || path[r][c]) return false;


        path[r][c] = 1;

        bool res  =  dfs(b,w,r+1,c,i+1,path) || dfs(b,w,r-1,c,i+1,path) ||dfs(b,w,r,c+1,i+1,path) ||dfs(b,w,r,c-1,i+1,path);

        path[r][c] = 0;

        return res;
        
    }
};
