class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;

        vector<int> cnt(26,0);

        for(char t : tasks){
            cnt[t-'A']++;
        }

        for(int c : cnt){
            if(c > 0) pq.push(c);
        }

        int t = 0;
        queue<pair<int,int>> q;
        while(!pq.empty() || !q.empty()){
            t++;

            if(pq.empty()){
                t = q.front().second;
            }
            else{
                int cnt = pq.top()-1;
                pq.pop();
                if(cnt>0){
                    q.push({cnt,t+n});
                }
            }

            if(!q.empty() && q.front().second == t){
                pq.push(q.front().first);
                q.pop();
            }
        }

        return t;
    }
};
