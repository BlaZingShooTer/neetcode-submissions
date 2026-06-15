class Solution {

    struct cmp {
    bool operator()(const pair<pair<int,int>,long long int> &a,
                    const pair<pair<int,int>,long long int> &b) {
        return a.second < b.second;  // min-heap by outer second
    }
    };

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<
    pair<pair<int,int>, long long int>, 
    vector<pair<pair<int,int>, long long int>>, 
    cmp
> minh;
       
        for(int i = 0;i<points.size();i++){
            
            int x1 = points[i][0];
            int y1 = points[i][1];

            long long int d = x1*x1 + y1*y1;

            minh.push({{x1,y1},d});

            if(minh.size() > k){
                minh.pop();
            }

        }
        vector<vector<int>> ans;
        while(!minh.empty()){
            int x1 = minh.top().first.first;
            int y1 = minh.top().first.second;
            ans.push_back({x1,y1});
            minh.pop();
        }

        return ans;
        

    }
};
