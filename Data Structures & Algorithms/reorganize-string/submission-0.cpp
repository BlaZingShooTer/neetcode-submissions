class Solution {
public:
    string reorganizeString(string s) {

        // Count frequency of each character
        unordered_map<char, int> freq;

        for (char c : s)
            freq[c]++;

        // Max Heap -> {frequency, character}
        priority_queue<pair<int, char>> pq;

        for (auto &x : freq)
            pq.push({x.second, x.first});

        string ans;

        while (pq.size() >= 2) {

            // Pick the two most frequent characters
            auto [cnt1, ch1] = pq.top();
            pq.pop();

            auto [cnt2, ch2] = pq.top();
            pq.pop();

            // Append both characters
            ans += ch1;
            ans += ch2;

            // One occurrence of each character is used
            cnt1--;
            cnt2--;

            // If still remaining, push back
            if (cnt1 > 0)
                pq.push({cnt1, ch1});

            if (cnt2 > 0)
                pq.push({cnt2, ch2});
        }

        // One character may still remain
        if (!pq.empty()) {

            auto [cnt, ch] = pq.top();

            // More than one occurrence left -> impossible
            if (cnt > 1)
                return "";

            // Check adjacent character
            if (!ans.empty() && ans.back() == ch)
                return "";

            ans += ch;
        }

        return ans;
    }
};