class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for(int i : stones){
            pq.push(i);
        }

        while(!pq.empty()){

            if(pq.size() == 1) return pq.top();
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();

            if(x > y) {
                y = x - y;
                pq.push(y);

            }
      
        
        }

        return  pq.empty()? 0: pq.top();
    }
};
