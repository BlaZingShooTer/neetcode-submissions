class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;

        int l = 0;
        int r = x / 2;
        int res = 0;

        while (l <= r) {
            int m = l + (r - l) / 2;
            long long sq = 1LL * m * m;

            if (sq == x) {
                return m;
            }
            else if (sq > x) {
                r = m - 1;
            }
            else {
                res = m;
                l = m + 1;
            }
        }

        return res;
    }
};