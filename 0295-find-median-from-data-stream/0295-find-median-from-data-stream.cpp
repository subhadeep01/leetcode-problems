class MedianFinder {
public:
    priority_queue<int> small,large;//max heap
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        small.push(num);
        large.push(-small.top());
        small.pop();
        if(large.size()>small.size())
        {
            small.push(-large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        return small.size()>large.size()? small.top(): (small.top()-large.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */