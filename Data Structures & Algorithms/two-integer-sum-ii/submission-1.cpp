class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int,int> mp;

        for(int i = 0;i<numbers.size();i++){
            int rem = target - numbers[i];
            if(mp.count(rem)){
                return {mp[rem],i+1};
            }

            mp.insert({numbers[i] , i+1});
        }
    }
};
