class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if(arr.size() == k)return arr;

        int l = 0;
        int r = arr.size()-1;
        
        while(r-l+1>k){


            if(abs(arr[l] - x) <= abs(arr[r] - x)){
                r--;
            }
            else{
                l++;
            }

        }

        vector<int> temp(arr.begin()+l,arr.begin()+l+k);
        return temp;

        
    }
};