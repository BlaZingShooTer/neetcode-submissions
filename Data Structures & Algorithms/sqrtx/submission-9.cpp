class Solution {
public:
    int mySqrt(int x) {

        if(x < 2) return x;

        int r = x/2;
        int l = 1;

        while(l<=r)
        {   
            long long m = (long long)(l + (r-l)/2);

            if(m*m == x){
                return m;
            }
            else if(m*m > x){
                r = m-1;
            }
            else{
                l = m+1;
            }

        }

        return r;

    }
};