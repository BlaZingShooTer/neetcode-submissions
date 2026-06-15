class Solution {
public:
    vector<int> vec;
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vec.resize(n+1,-1);
        return min(func(n-1,cost) , func(n-2,cost));
    }

    int func(int n , vector<int> &cost ){
        if(n == 0 || n ==1) return cost[n];
        

        if(n < 0) return 0;

        if(vec[n]!= -1) return vec[n];

        int l = func(n-1,cost) + cost[n];
        int r = func(n-2,cost) + cost[n];

        return vec[n] = min(l,r);
    }
};
