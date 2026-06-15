#include<string>
class Solution {
public:
    string multiply(string num1, string num2) {
        
        long long x1 = stoll(num1);
        long long x2 = stoll(num2);

        x1 = x1 * x2;

        string s  = to_string(x1);

        return s;
    }
};
