class MedianFinder {
public:
    
    vector<int> ans;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        ans.push_back(num);
    
    }
    
    double findMedian() {
        sort(ans.begin(),ans.end());
        int n = ans.size();
        if(n%2 == 0){
        
            

           double val = double(ans[n/2]) + double(ans[n/2 - 1]);

           return val/2;



        } 

        else{
            return ans[n/2];

        }

        
    }
};
