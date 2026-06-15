class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        priority_queue<int> mh;

        vector<int> count(26,0);
        for(int i = 0;i<tasks.size();i++){
            count[tasks[i] - 'A']++;
        }

        for(int cnt : count){
            if(cnt > 0){
                mh.push(cnt);
            }
        }


        int t = 0;
        queue<pair<int,int>> q;
        while(!q.empty() || !mh.empty()){
            t++;

            if(mh.empty()){
                t = q.front().second;

            }
            else{
                int cnt = mh.top()-1;
                mh.pop();
                if(cnt > 0){
                    q.push({cnt , t + n});
                }
            }

            if(!q.empty() && q.front().second == t){
                mh.push(q.front().first);
                q.pop();
            }
        }
        return t;
        
    }
};
