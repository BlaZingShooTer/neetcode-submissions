class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int target) {
        int n = m.size();
        int k = m[0].size();
        int i = 0;
        
        while(i<n){
            
            if(m[i][0] <= target && m[i][k-1] >= target){
                int l = 0;
                int h = k-1;
                while(l<=h){
                    int p = (h+l)/2;

                    if(m[i][p] == target ) return true;
                    else if(m[i][p] > target){
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
