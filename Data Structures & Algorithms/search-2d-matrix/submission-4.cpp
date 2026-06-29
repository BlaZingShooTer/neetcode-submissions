class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        int i = 0;
        while(i<r){
            if(matrix[i][0] <= target && matrix[i][c-1] >= target){
                int l = 0;
                int h = c-1;
                while(l <= h){
                    int p = (l+h)/2;

                    if(matrix[i][p] == target){
                        return true;
                    }
                    else if(matrix[i][p] > target){
                        h = p-1;
                    }
                    else{
                        l = p+1;
                    }
                }
            }
            i++;
        }

        return false;
    }
};
