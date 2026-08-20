class MedianFinder {
private:
    vector<int>v;
public:
    MedianFinder() {

    }
    
    void addNum(int num) {
        int pos = lower_bound(v.begin(),v.end(),num)-v.begin();
        v.insert(pos+v.begin(),num);
    }
    
    double findMedian() {
        if(v.size()%2==0){
            return (v[v.size()/2]+v[v.size()/2-1])/2.0;
        }
        else{
            return v[v.size()/2];
        }
    }
};
