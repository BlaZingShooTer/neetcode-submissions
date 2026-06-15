class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l =0;
        int r = 0;
        vector<int> var;
        while(l<m && r<n){

            if(nums1[l] > nums2[r]){
                var.push_back(nums2[r]);
                r++;
            }
            else
            {
                var.push_back(nums1[l]);
                l++;
            }
        }

        while(l<m){
            var.push_back(nums1[l]);
            l++;
        }

        while(r<n){
            var.push_back(nums2[r]);
            r++;
        }

        nums1 = var;
    }
};