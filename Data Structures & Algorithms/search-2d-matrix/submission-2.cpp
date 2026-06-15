class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int t) {
        int r = m.size();
        int c = m[0].size();

        int i=0;

        while(i<r){
            if(m[i][0] <= t && m[i][c-1] >= t){
                int l =0;
                int h = c-1;

                while(l<=h){
                    int p = l + (h-l)/2;

                    if(m[i][p] == t) return true;
                    else if(m[i][p] > t){
                        h = p-1;
                    }
                    else{
                        l = p+1;
                    }
                }

                return false;
            }
            i++;
        }

        return false;
    }
};
