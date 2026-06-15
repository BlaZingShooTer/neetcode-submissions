class Solution {
public:
        vector<int> vec;
    int climbStairs(int n) {
        vec.resize(n+1,-1);
        return func(n);
    }

    int func(int n){
        if(n == 1 || n == 0) return 1;
        if(n<0) return 0;
        
        if(vec[n]!=-1) return vec[n];

        int l = func(n-1) ;
        int r = func(n-2) ;

        return  vec[n] = l + r;
    }
};
