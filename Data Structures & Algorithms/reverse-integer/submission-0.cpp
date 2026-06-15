#include <algorithm> // for std::reverse
#include <string>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        
    long long x1 = pow(2,31);
    long long y1 = -x1;
    long long y2 = x1 -1;

    string s = to_string(x);

    if(x > 0){
       std::reverse(s.begin(),s.end());
    }
    else{
       std::reverse(s.begin()+1,s.end());

    }

    long long l = stoll(s);

    if(l > y2 || l<y1){
        return 0;
    }
    int m = stoi(s);
    return m;

         
    }
};
