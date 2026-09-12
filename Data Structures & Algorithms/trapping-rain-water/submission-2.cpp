class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        vector<int> left_max(n,0);

        left_max[0] = h[0];

        for(int i = 1;i<n;i++){
            left_max[i] = max(left_max[i-1] , h[i]);
        }

        vector<int> right_max(n,0);

        right_max[n-1] = h[n-1];

        for(int i = n-2;i>=0;i--){
            right_max[i] = max(right_max[i+1] , h[i]);
        }


        int ans = 0;

        for(int i = 0;i<n;i++){

            ans += min(right_max[i] , left_max[i]) - h[i];
        }

        return ans;

    }
};
