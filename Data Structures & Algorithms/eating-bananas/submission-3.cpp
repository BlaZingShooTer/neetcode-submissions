class Solution {
public:

    int rate(int k , vector<int>& p){

        int ans = 0;

        for(int i = 0;i<p.size();i++){

            ans += (p[i] + k -1)/k;

        }

        return ans;

    }


    int minEatingSpeed(vector<int>& piles, int h) {
        int ans = 0;
        int l =1;
        int r = *max_element(piles.begin(),piles.end());

        while(l<=r)
        {
            int m = l + (r-l)/2;

            if( rate(m,piles) <= h ){
                ans = m;
                r = m-1;
            }
            else{
                l = m+1;
            }
            
        }

        return ans;
        

    }

};
