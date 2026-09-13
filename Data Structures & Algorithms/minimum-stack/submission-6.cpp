class MinStack {
    stack<int> st;
    stack<int> minst;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);

        if(minst.empty()){
            minst.push(val);
        }
        else if(!minst.empty() && minst.top() >= val){
            minst.push(val);
        }
    }
    
    void pop() {
        if(st.top() == minst.top()){
            st.pop();
            minst.pop();
        }
        else{
            st.pop();
        }
        
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};
