class Solution {
public:
    int minEatingSpeed(vector<int>& p, int h) {
        int r = *max_element(p.begin(),p.end());
        int l = 1;
        int res = r;
        while(l<=r){
            int k = (l+r)/2;

            long long tt = 0;

            for(int i : p){
                tt+= i/k + (i%k!=0);
            }

            if(tt<=h){
                res = k;
                r = k-1;
            }
            else{
                l = k+1;
            }
        }

        return res;

    }
};
