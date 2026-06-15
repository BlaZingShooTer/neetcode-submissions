class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        if(n == 0) return 1;
        if(n > 0) {
            for(int i = 1;i<=n;i++){
            ans = ans * x;
            }
        }
        else{
            for(int i = 1;i<= abs(n);i++){
                ans =  ans / x;
            }
        }

        return ans;
    }
};
