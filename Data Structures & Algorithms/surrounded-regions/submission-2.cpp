class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();

        vector<vector<bool>> vis(r,vector<bool>(c,false));


        for(int i = 0;i<r;i++){
            if(!vis[i][0] && board[i][0] == 'O'){
                dfs(i,0,vis,board);
            }


            if(!vis[i][c-1] && board[i][c-1] == 'O'){
                dfs(i,c-1,vis,board);
            }

        }

        
        for(int i = 0;i<c;i++){
            if(!vis[0][i] && board[0][i] == 'O'){
                dfs(0,i,vis,board);
            }


            if(!vis[r-1][i] && board[r-1][i] == 'O'){
                dfs(r-1,i,vis,board);
            }

        }

        for(int i = 0;i<r;i++){
            for(int j =0;j<c;j++){
                if(board[i][j] == 'T'){
                    board[i][j] ='O';
                }
                else if(board[i][j] =='O'){
                    board[i][j] ='X';
                }
            }
        }

    }

    void dfs(int r , int c , vector<vector<bool>>&vis ,vector<vector<char>>& board){

        vis[r][c] = true;
        board[r][c] = 'T';

        int dr[4] = {-1,1,0,0};
        int dc[4] = {0,0,-1,1};

        for(int i = 0;i<4;i++){
            
            int nr = dr[i] + r;
            int nc = dc[i] + c;

            if(nr>=0 && nc >=0 && nr < board.size() && nc < board[0].size() && !vis[nr][nc] && board[nr][nc] == 'O'){
                dfs(nr,nc,vis,board);
            }
        }

    }
};
