class MedianFinder {
    priority_queue<int, vector<int>, less<int>> sh;
    priority_queue<int, vector<int>, greater<int>> lh;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        sh.push(num);

        if(!lh.empty() && sh.top() > lh.top()){
            lh.push(sh.top());
            sh.pop();
        }

        if(sh.size() >lh.size() + 1){
            lh.push(sh.top());
            sh.pop();
        }

        if(lh.size() > sh.size() +1){
            sh.push(lh.top());
            lh.pop();
        }
    }
    
    double findMedian() {
        if(sh.size() == lh.size()){
            return (lh.top() + sh.top())/2.0;
        }
        else if(sh.size() > lh.size()){
            return sh.top();
        }
        else{
            return lh.top();
        }
        
    }
};
