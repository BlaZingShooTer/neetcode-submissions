#include <string>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        // 1. Count target character frequencies (case-sensitive)
        unordered_map<char, int> target_counts;
        for (char c : t) {
            target_counts[c]++;
        }

        unordered_map<char, int> window_counts;
        int required = target_counts.size(); // Total unique characters to satisfy
        int formed = 0;                       // Unique characters meeting target frequency

        int l = 0;
        int min_len = INT_MAX;
        int min_start = 0;

        // 2. Expand window using pointer r
        for (int r = 0; r < s.length(); r++) {
            char right_char = s[r];
            window_counts[right_char]++;

            // Increment formed if current character matches required count exactly
            if (target_counts.count(right_char) && 
                window_counts[right_char] == target_counts[right_char]) {
                formed++;
            }

            // 3. Shrink window from the left while it remains valid
            while (formed == required) {
                // Update smallest window seen so far
                if (r - l + 1 < min_len) {
                    min_len = r - l + 1;
                    min_start = l;
                }

                // Remove character at l
                char left_char = s[l];
                window_counts[left_char]--;

                // If removing this character breaks its required count, decrement formed
                if (target_counts.count(left_char) && 
                    window_counts[left_char] < target_counts[left_char]) {
                    formed--;
                }

                l++; // Advance left pointer
            }
        }

        // 4. Return empty string if no valid window was found
        return (min_len == INT_MAX) ? "" : s.substr(min_start, min_len);
    }
};