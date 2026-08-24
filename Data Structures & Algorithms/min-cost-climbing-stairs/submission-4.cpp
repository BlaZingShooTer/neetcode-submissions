class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> vis(n+1,-1);

        return  min(func(n-1,vis,cost),func(n-2,vis,cost));
    }

    int func(int i, vector<int> &vis , vector<int> &cost){
        if( i== 0 || i == 1) return cost[i];

        if( i<0) return 0;

        if(vis[i]!=-1) return vis[i];

        int l = cost[i] + func(i-1,vis,cost);
        int r = cost[i] + func(i-2,vis,cost);

        return vis[i] = min(l,r);
    }
};
