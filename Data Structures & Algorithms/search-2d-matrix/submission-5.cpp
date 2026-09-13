class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int r = 0;
        int c = matrix[0].size();

        while(r<matrix.size()){

            if(target >= matrix[r][0] && target <= matrix[r][c-1])
            {
                int l = 0;
                int k = c-1;

                while(l<=k){

                    int m = l+ (k-l)/2;

                    if(target == matrix[r][m]) return true;

                    else if(target > matrix[r][m]){
                        l = m+1;
                    }
                    else{
                        k = m-1;
                    }

                }

            }
            r++;
        }

        return false;

    }
};
