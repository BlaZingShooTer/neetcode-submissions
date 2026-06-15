class FreqStack {
public:
    map<int,int> f;
    map<int, stack<int>> gp;
    int maxf = 0;


    FreqStack() {
        
    }
    
    void push(int val) {
        int fr = f[val]++;
        maxf = max(maxf,fr);

        gp[fr].push(val);
    }
    
    int pop() {
        int val = gp[maxf].top();
        gp[maxf].pop();

        f[val]--;

        if(gp[maxf].empty()){
            maxf--;
        }

        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */