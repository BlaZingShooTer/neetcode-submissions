class Solution {
public:
    string reorganizeString(string s) {
        // 1. Count frequencies
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        // 2. Push non-zero counts into a max-heap
        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                // Early exit check: impossible if count > (length + 1) / 2
                if (freq[i] > (s.length() + 1) / 2) return "";
                pq.push({freq[i], 'a' + i});
            }
        }

        // 3. Greedily build the result using a cooldown holder
        string result = "";
        pair<int, char> prev = {0, '#'};

        while (!pq.empty()) {
            auto [cnt, ch] = pq.top();
            pq.pop();

            result += ch;
            cnt--;

            // If a previous character was waiting, it's safe to return to the heap
            if (prev.first > 0) {
                pq.push(prev);
            }

            // Hold the current character aside
            prev = {cnt, ch};
        }

        return (result.length() == s.length()) ? result : "";
    }
};