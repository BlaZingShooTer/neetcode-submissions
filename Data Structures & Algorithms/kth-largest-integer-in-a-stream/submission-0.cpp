class KthLargest {
public:
    priority_queue<int, vector<int> , greater<int>> pq;
    int l = 0;
    KthLargest(int k, vector<int>& nums) {
        l = k;
        for(int i = 0;i<nums.size();i++){
            pq.push(nums[i]);

            if(pq.size() > k){
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);

        if(pq.size() > l){
            pq.pop();
        }

        return pq.top();
        
    }
};
