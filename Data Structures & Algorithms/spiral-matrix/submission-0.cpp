class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        int r_i = 0;
        int r_f = matrix.size();

        int c_i = 0;
        int c_f = matrix[0].size();

        while (r_i < r_f && c_i < c_f) {

            // top row
            for (int i = c_i; i < c_f; i++) {
                ans.push_back(matrix[r_i][i]);
            }
            r_i++;

            // right column
            for (int i = r_i; i < r_f; i++) {
                ans.push_back(matrix[i][c_f - 1]);
            }
            c_f--;

            // bottom row
            if (r_i < r_f) {
                for (int i = c_f - 1; i >= c_i; i--) {
                    ans.push_back(matrix[r_f - 1][i]);
                }
                r_f--;
            }

            // left column
            if (c_i < c_f) {
                for (int i = r_f - 1; i >= r_i; i--) {
                    ans.push_back(matrix[i][c_i]);
                }
                c_i++;
            }
        }

        return ans;
    }
};