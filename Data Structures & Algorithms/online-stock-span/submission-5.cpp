class StockSpanner {
    stack<int> s1;
    stack<int> s2;

public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        int span = 1;
        if(s1.empty()){
            s1.push(price);
            return 1;
        }


    

            while( !s1.empty() && s1.top() <= price){
            span++;
            s2.push(s1.top());
            s1.pop();
            }

            while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
            }
            
            while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
            }

        

        s1.push(price);

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */