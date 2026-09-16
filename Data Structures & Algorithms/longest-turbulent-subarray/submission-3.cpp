class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        
        int n = arr.size();

        int ml = 1;
        int cl = 1;
        int p = 0;

        for(int i = 1;i<n;i++){
            int c = 0;
            if(arr[i-1] > arr[i]){
                c = 1;
            }
            else if(arr[i-1] < arr[i]){
                c = -1;
            }

            if(c == 0){
                cl = 1;
            }
            else if(c == -p){
                cl+= 1;
            }
            else{
                cl = 2;
            }

            ml = max(ml , cl);
            p = c;
        }

        return ml;

    }
};