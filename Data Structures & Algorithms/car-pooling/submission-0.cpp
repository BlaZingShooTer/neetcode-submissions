class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // 1. Build the list of events: {location, passenger_change}
        vector<pair<int, int>> events;
        for (const auto& trip : trips) {
            int numPassengers = trip[0];
            int from = trip[1];
            int to = trip[2];

            events.push_back({from, numPassengers});   // 🟢 Boarding (+num)
            events.push_back({to, -numPassengers});    // 🔴 Drop-off (-num)
        }

        // 2. Sort events by location.
        // Ties break naturally: drop-offs (negative) come before pickups (positive).
        sort(events.begin(), events.end());

        // 3. Sweep through the timeline
        int currentPassengers = 0;
        for (const auto& [location, change] : events) {
            currentPassengers += change;
            
            if (currentPassengers > capacity) {
                return false;
            }
        }

        return true;
    }
};