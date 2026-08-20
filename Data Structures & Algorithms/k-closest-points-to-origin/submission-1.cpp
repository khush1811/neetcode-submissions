class Solution {
private:
    int dist(vector<int>&v){
        return v[0]*v[0]+v[1]*v[1];
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>>pq;
        for(auto &point:points){
            pq.push({dist(point),point});
        }
        vector<vector<int>>ans;
        while(k--){
            auto [dis,v]=pq.top();pq.pop();
            ans.push_back(v);
        }
        return ans;
    }
};
