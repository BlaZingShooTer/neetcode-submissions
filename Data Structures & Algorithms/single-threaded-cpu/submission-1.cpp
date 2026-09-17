class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {

        vector<vector<int>> pro;

        for(int i = 0;i<tasks.size();i++){

            pro.push_back({tasks[i][0],tasks[i][1], i});

        }
        sort(pro.begin(),pro.end());


        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;

        long long time = 0;
        int i = 0;
        vector<int> ans;

        while(i<tasks.size() || !pq.empty()){

            if(pq.empty() && time <= pro[i][0]){
                time = pro[i][0];
            }


            while(i<tasks.size() && pro[i][0] <= time){
                pq.push({pro[i][1],pro[i][2]});
                i++;
            }


            auto [protime , index] = pq.top();
            pq.pop();
            time += protime;
            ans.push_back(index);



        }

        return ans;

    }
};