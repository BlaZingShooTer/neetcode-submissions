class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if(k==arr.size()) return arr;

        int l =0;
        int r = arr.size()-1;

        while(r-l+1 > k){
           
           if(abs(x-arr[l]) > abs(x - arr[r])){
            l++;
           }
           else{
            r--;
           }
        }

        return vector<int>(arr.begin() + l,
                       arr.begin() + r + 1);
        


    }
};