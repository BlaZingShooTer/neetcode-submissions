class FreqStack {

    unordered_map<int,int> mp;

    unordered_map<int, stack<int>> mp1;

    int maxf = 0;
   
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        
        mp[val]++;

        mp1[mp[val]].push(val);
        
        maxf = max(maxf , mp[val]);

        
    }
    
    int pop() {


        int x = mp1[maxf].top();

        mp[x]--;

        mp1[maxf].pop();

        if(mp1[maxf].empty()){
            maxf--;
        }

        return x;
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */