class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for(int i = 0;i<stones.size();i++){
            pq.push(stones[i]);
        }

        while(pq.size()>1){
            int x = 0;
            if(!pq.empty())
            {x = pq.top();
            pq.pop();}
            
            int y = 0;
            if(!pq.empty()){ y = pq.top();
            pq.pop();}

            if(x>y) pq.push(x-y);  
        }
        pq.push(0);
        return pq.top();
    }
};
