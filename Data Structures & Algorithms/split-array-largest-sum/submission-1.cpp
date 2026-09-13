class Solution {
public:

    int count(vector<int> & n , int sum){
        int s = 0;
        int cnt = 1;
        for(int a : n){

            
            if(s+a > sum){
                cnt++;
                s = a;
            }
            else{
                s+= a;
            }


        }
        return cnt;
    }

    int splitArray(vector<int>& nums, int k) {

        int l = *max_element(nums.begin(),nums.end());

        int r = accumulate(nums.begin(),nums.end(),0);

        while(l<=r){

            int m = l + (r-l)/2;

            if(count(nums,m) <= k){
                r =m-1;
            }
            else if(count(nums,m) > k){
                l = m+1;
            }
            

        }

        return l;

        
    }


};