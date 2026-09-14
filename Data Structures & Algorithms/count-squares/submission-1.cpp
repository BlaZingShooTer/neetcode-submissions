class CountSquares {

    map<pair<int,int>,int> mp;

public:
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        mp[{point[0],point[1]}]++;
    }
    
    int count(vector<int> point) {
        
        int x2 = point[0];
        int y2 = point[1];

        int ans = 0;

        for(auto it : mp){

            int f = it.second;

            int x1 = it.first.first;
            int y1 = it.first.second;

            if(abs(x1-x2) != abs(y1-y2) || x1 == x2){
                continue;
            }

            ans +=  f * mp[{x2,y1}] * mp[{x1,y2}];
        }
        return ans;

    }
};
