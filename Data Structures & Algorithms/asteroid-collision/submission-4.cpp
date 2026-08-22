class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> ans;

        for (int i = 0; i < asteroids.size(); i++) {
            
            int asteroid = asteroids[i];
            bool destroyed = false;

            // Check collisions
            while (!ans.empty() && ans.top() > 0 && asteroid < 0) {

                // Stack asteroid is smaller
                if (ans.top() < abs(asteroid)) {
                    ans.pop();
                }

                // Both asteroids are equal
                else if (ans.top() == abs(asteroid)) {
                    ans.pop();
                    destroyed = true;
                    break;
                }

                // Current asteroid is smaller
                else {
                    destroyed = true;
                    break;
                }
            }

            // Push asteroid if it survived
            if (!destroyed) {
                ans.push(asteroid);
            }
        }

        // Convert stack to vector
        vector<int> result;

        while (!ans.empty()) {
            result.push_back(ans.top());
            ans.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};