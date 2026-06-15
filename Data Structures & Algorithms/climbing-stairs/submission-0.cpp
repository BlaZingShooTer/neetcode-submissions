class Solution {
public:
    int climbStairs(int n) {
        return func(n);
    }

    int func(int n){
        if(n == 1) return 1;
        if(n == 0) return 1;
        if(n<0) return 0;


        int l = func(n-1) ;
        int r = func(n-2) ;

        return l + r;
    }
};
