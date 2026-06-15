class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> mp;  // value -> index

        for (int i = 0; i < numbers.size(); i++) {
            int diff = target - numbers[i];

            // if we already saw the needed value
            if (mp.count(diff)) {
                return {mp[diff]+1, i+1};
            }

            // store current number
            mp[numbers[i]] = i;
        }

        return {-1, -1};  // if no pair found
    }
};
