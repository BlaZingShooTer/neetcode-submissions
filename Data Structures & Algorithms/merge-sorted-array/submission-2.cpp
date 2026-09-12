class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        vector<int> temp;

        int l =0;
        int r = 0;

        while(l<m &&  r < n){
            if(nums1[l] >= nums2[r]){
                temp.push_back(nums2[r]);
                r++;
            }
            else{

                temp.push_back(nums1[l]);
                l++;
            }
        }

        while(l!=m){
            temp.push_back(nums1[l]);
            l++;
        }

        
        while(r!=n){
            temp.push_back(nums2[r]);
            r++;
        }


        nums1 = temp;

    }
};