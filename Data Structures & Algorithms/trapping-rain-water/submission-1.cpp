class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();

        vector<int> lmax(n);
        vector<int> rmax(n);

        lmax[0] = h[0];
        for(int i = 1;i<n;i++){
            lmax[i] = max(lmax[i-1], h[i]);
        }

        rmax[n-1] = h[n-1];
        for(int i = n-2;i>=0;i--){
            rmax[i] = max(rmax[i+1],h[i]);
        }

        int res = 0;

        for(int i = 0;i<n;i++){
            res += min(lmax[i], rmax[i]) - h[i];
        }

        return res;
    }
};
