class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int l = 0;
        int r = 0;
        vector<int>ans;
        while(l<nums1.size() && r<nums2.size()){

            if(nums1[l] > nums2[r]){
                ans.push_back(nums2[r]);
                r++;
            }
            else{
                ans.push_back(nums1[l]);
                l++;
            }

        }

        if(l<nums1.size()){
            while(l<nums1.size()){
                ans.push_back(nums1[l]);
                l++;
            }
        }
        if(r<nums2.size()){
            while(r<nums2.size()){
                ans.push_back(nums2[r]);
                r++;
            }
        }
        int n = ans.size();
        if(ans.size()%2==0){
            
            double x = ans[(n/2)-1] + ans[n/2];
            return x/2;
        }
        
        return ans[n/2];
    }
};
