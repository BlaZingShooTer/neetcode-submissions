class Solution {
public:


    int days(int cap, vector<int>&weights){

        int d =1;
        int totalw = 0;

        for(auto w : weights){
            if(totalw +w >cap){
                d++;
                totalw = w;
            }else{
                totalw += w;
            }

        }

        return d;
    }


    int shipWithinDays(vector<int>& w, int d) {
        
        int l = *max_element(w.begin(),w.end());

        int r = accumulate(w.begin(),w.end(),0);

        while(l<=r){

            int m = l + (r-l)/2;

            if(days(m,w) > d ){
                l = m+1;
            }
            else{
                r = m-1;
            }


        }

        return l;

    }


};