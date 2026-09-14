class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> count(n,0);

        sort(meetings.begin(),meetings.end());

        priority_queue<int , vector<int> , greater<int>> free;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy;

        for(int i = 0;i<n;i++){
            free.push(i);
        }

        for(auto it : meetings){
            long long strt = it[0];
            long long end = it[1];

            while (!busy.empty() && busy.top().first <= strt) {
                free.push(busy.top().second);
                busy.pop();
            }

            if(!free.empty()){
                int room = free.top();
                free.pop();
                long long ed = end;

                busy.push({end,room});

                count[room]++;
            }
            else
            {
                long long wait = busy.top().first - strt;
                int room = busy.top().second;
                busy.pop();

                busy.push({wait + end,room});

                count[room]++;


            }
        }

       int maxroom = 0;

        for (int i = 1; i < count.size(); i++) {
            if (count[i] > count[maxroom]) {
                maxroom = i;
            }
        }

        return maxroom;

    }
};