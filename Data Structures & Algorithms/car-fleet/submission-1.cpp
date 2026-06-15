class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,double>> cars;
        
        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }
        
        // nearest to target first
        sort(cars.rbegin(), cars.rend());
        
        stack<double> st;  // arrival times of fleets
        
        for (auto &car : cars) {
            double t = car.second;
            
            if (st.empty() || t > st.top()) {
                st.push(t);  // new fleet
            }
            // else merge → do nothing
        }
        
        return st.size();
    }
};
