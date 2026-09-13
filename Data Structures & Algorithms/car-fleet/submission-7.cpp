class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        stack<double> st;

        vector<pair<int,int>> cars;

        for(int i = 0;i<position.size();i++){  
            cars.push_back({position[i] , speed[i]});
        }

      sort(cars.begin(), cars.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
    return a.first > b.first;
});

        for(int i = 0;i<cars.size();i++){
            
            double time = (double)(target - cars[i].first)/cars[i].second;

            if(!st.empty() && st.top() >= time){
                
               continue;
            }
            
            st.push(time);

        }

        return st.size();

    }
};
