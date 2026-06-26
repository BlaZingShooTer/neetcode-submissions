class CountSquares {
public:

    map<pair<int,int>,int> cnt;

    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        cnt[{point[0],point[1]}]++;
    }
    
    int count(vector<int> point) {
        int px = point[0];
        int py = point[1];

        int ans = 0;

        for(auto &[p,f] : cnt){

            int x = p.first;
            int y = p.second;

            if(x == px || abs(x-px) != abs(y-py)){
                continue;
            }

            ans += f * cnt[{x,py}] * cnt[{px,y}];
        }


        return ans;


    }
};
