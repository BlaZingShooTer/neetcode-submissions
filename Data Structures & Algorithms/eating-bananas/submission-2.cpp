class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        while (l <= r) {

            int m = l + (r - l) / 2;

            if (caltime(piles, m) > h) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return l;
    }

    int caltime(const vector<int>& piles, int speed) {
        int time = 0;

        for (int bananas : piles) {
            time += (bananas + speed - 1) / speed;
        }

        return time;
    }
};