class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
       

        stack<pair<int,int>> st;

       

        for(int i = 0;i<matrix.size();i++){
            for(int j = 0;j<matrix[0].size();j++){
                
                if(matrix[i][j] == 0){
                    st.push({i,j});
                }

            }
        }


        while(!st.empty()){
            
            int i = st.top().first;
            int j = st.top().second;

            st.pop();

            for(int c = 0;c<matrix[0].size();c++){
                matrix[i][c] = 0;
            }

            for(int r = 0;r<matrix.size();r++){
                matrix[r][j] = 0;
            }

            
            
        }
    }
};
