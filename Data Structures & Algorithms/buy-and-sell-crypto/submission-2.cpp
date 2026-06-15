class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxp = 0;

        int p = prices[0];

        for(int i=0; i<prices.size();i++){
            maxp = max(maxp, prices[i] - p);

            p = min(p,prices[i]);
        }

        return maxp;
    }
};
