class MedianFinder {
public:
    priority_queue<int>maxHeap;
    priority_queue<int, vector<int>, greater<int>>minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        minHeap.push(num);
        maxHeap.push(minHeap.top());
        minHeap.pop();

        while(minHeap.size() < maxHeap.size()){
            int num = maxHeap.top();
            maxHeap.pop();
            minHeap.push(num);
        }
    }
    
    double findMedian() {
        if(minHeap.size() == maxHeap.size()){
            int x = minHeap.top();
            int y = maxHeap.top();
            return (x + y) / 2.0;
        }
        else{
            return minHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */