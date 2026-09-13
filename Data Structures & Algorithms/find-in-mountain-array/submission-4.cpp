class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        // 1. Find the peak index using binary search
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                l = mid + 1; // Climbing up
            } else {
                r = mid;     // Reached peak or going down
            }
        }
        int peak = l;

        // 2. Binary search on strictly increasing left side [0, peak]
        l = 0;
        r = peak;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int val = mountainArr.get(mid);

            if (val == target) return mid;
            else if (val < target) l = mid + 1;
            else r = mid - 1;
        }

        // 3. Binary search on strictly decreasing right side [peak + 1, n - 1]
        l = peak + 1;
        r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int val = mountainArr.get(mid);

            if (val == target) return mid;
            else if (val > target) l = mid + 1; // Inverted: larger elements are to the left
            else r = mid - 1;
        }

        return -1;
    }
};