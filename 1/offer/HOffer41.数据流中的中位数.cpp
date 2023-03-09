class MedianFinder {
public:
    vector<int> container;
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        container.push_back(num);
        sort(container.begin(), container.end());
    }
    
    double findMedian() {
        if(container.empty()){
            return 0.0;
        }
        else{
            int n = container.size();
            if(n / 2 == 0){
                return (container[n/2-1] + container[n/2]) / 2;
            }
            else return container[(n-1)/2];
        }      
        
    }
};