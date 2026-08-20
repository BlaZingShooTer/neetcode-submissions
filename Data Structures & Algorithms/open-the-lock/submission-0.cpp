class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if(target == "0000") return 0;

        unordered_set<string> visit(deadends.begin(), deadends.end()); // store visited and deadends

        if(visit.count("0000")) return -1;

        queue<string> q;
        q.push("0000");

        visit.insert("0000");

        int steps = 0;

        while(!q.empty()){
            steps++;

            for(int i = q.size();i>0;i-- ){
                string l = q.front(); q.pop();

                for(int j = 0;j<4;j++){
                    for(int m : {1,-1}){
                        string nl =  l;
                        nl[j] = (nl[j] - '0' + m + 10)%10 + '0';


                        if(visit.count(nl))continue;
                        if(nl == target) return steps;

                        q.push(nl);
                        visit.insert(nl);
                    }
                }
            }
        }

        return -1;



    }
};