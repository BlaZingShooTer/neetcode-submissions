class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        int ri = 0;
        int rf = matrix.size();

        int ci = 0;
        int cf = matrix[0].size();

        while(ri < rf && ci < cf){

            for(int i = ci; i < cf; i++){
                ans.push_back(matrix[ri][i]);
            }

            ri++;

            for(int i = ri; i < rf; i++){
                ans.push_back(matrix[i][cf-1]);
            }
            
            cf--;

            if(ri<rf){

                for(int i = cf-1; i >= ci; i--){
                ans.push_back(matrix[rf-1][i]);
                }

                rf--;
                
            }


            if(ci<cf){

                for(int i = rf-1; i >= ri; i--)
                {
                    ans.push_back(matrix[i][ci]);

                }

            }

            ci++;

        }

        return ans;
    }
};
