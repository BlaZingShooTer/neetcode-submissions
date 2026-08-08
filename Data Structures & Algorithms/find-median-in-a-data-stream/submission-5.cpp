class MedianFinder {
public:
    
    priority_queue<int> leftMax; // max heap
    priority_queue<int, vector<int>, greater<int>> rightMin; // min heap

    MedianFinder() {
    }
    
    void addNum(int num) {

        leftMax.push(num);
        
        // Move largest from left to right
        rightMin.push(leftMax.top());
        leftMax.pop();

        // Balance sizes
        if (rightMin.size() > leftMax.size()) {
            leftMax.push(rightMin.top());
            rightMin.pop();
        }
    }
    
    double findMedian() {
        if (leftMax.size() > rightMin.size()) {
            return leftMax.top();
        }
        return (leftMax.top() + rightMin.top()) / 2.0;
    }
};
