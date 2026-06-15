/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> strt, ed;


        for(auto &i : intervals ){
            strt.push_back(i.start);
            ed.push_back(i.end);
        }


        sort(strt.begin(),strt.end());
        sort(ed.begin(),ed.end());


        int res = 0;
        int cnt = 0;
        int s = 0;
        int e = 0;

        while(s<intervals.size()){
            if(strt[s] < ed[e]){
                s++;
                cnt++;
            }
            else{
                e++;
                cnt--;
            }

            res =max(res, cnt);
        }

        return res;

    }
};
