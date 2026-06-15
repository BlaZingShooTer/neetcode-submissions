class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = INT_MIN;
        int minprice = INT_MAX;
        for(int i = 0;i<prices.size();i++){
            minprice = min(prices[i],minprice);
            int p = prices[i] - minprice;

            maxprofit = max(maxprofit,p);
        }

        return maxprofit;
    }
};
