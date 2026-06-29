class Solution {
public:
    int shipWithinDays(vector<int>& w, int d) {
        
        int l = *max_element(w.begin(),w.end());
        int r = accumulate(w.begin(), w.end(), 0);

        int res = r;

        while(l<=r){
            int cap = (l+r)/2;

            if(canShip(w,d,cap)){
                res = min(cap , res);
                r = cap - 1;
            }
            else{
                l = cap + 1;
            }
        }
        return res;

    }


    bool canShip(vector<int>&w , int days , int cap){

        int ships =1 , curcap = cap;

        for(int i = 0;i<w.size();i++){
            if(curcap - w[i] < 0 ){
                ships++;

                if(ships > days){
                    return false;
                }
                curcap = cap;
            }
            curcap -= w[i];
        }
        return true;
    }
};