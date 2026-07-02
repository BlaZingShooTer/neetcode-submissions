/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mA) {

        int length = mA.length();


        int l  =1;
        int r = length-2;
        int peak = 0;

        while( l <= r){
            int m = (l+r)/2;
            int left = mA.get(m-1);
            int mid = mA.get(m);
            int right = mA.get(m+1);

            if(left < mid && mid < right){
                l = m + 1;
            }
            else if(left > mid && mid > right){
                r = m - 1;
            }
            else{
                peak = m;
                break;
            }
        }

        l =0;
        r = peak -1;
        while( l<= r){
            int m = (l+r)/2;

            int val = mA.get(m);

            if(val < target){
                l = m + 1;
            }
            else if(val > target){
                r = m-1;
            }
            else{
                return m;
            }
        }

        l = peak;
        r = length - 1;

        while( l<= r){
            int m = (l+r)/2;

            int val = mA.get(m);
            if (val > target){
                l = m +1;
            }
            else if(val < target){
                r = m-1;
            }
            else{
                return m;
            }
        }
        return -1;
    }
};