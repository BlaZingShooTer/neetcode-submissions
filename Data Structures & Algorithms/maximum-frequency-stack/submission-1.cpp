#include <unordered_map>
#include <stack>
using namespace std;

class FreqStack {
public:
    unordered_map<int, int> freq;            // value -> frequency
    unordered_map<int, stack<int>> group;   // frequency -> stack of values
    int maxFreq = 0;

    FreqStack() {}

    void push(int val) {
        int f = ++freq[val];        // increase frequency
        maxFreq = max(maxFreq, f);  // update max
        group[f].push(val);         // push into that frequency stack
    }

    int pop() {
        int val = group[maxFreq].top();
        group[maxFreq].pop();

        freq[val]--;                // reduce frequency

        if (group[maxFreq].empty()) {
            maxFreq--;
        }

        return val;
    }
};
