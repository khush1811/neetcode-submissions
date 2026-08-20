class Solution {
private:
    vector<pair<int,int>>dirs={{0,1},{1,0},{0,-1},{-1,0}};
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({grid[0][0],{0,0}});
        vector<int>minVal(n*n,INT_MAX);
        minVal[0]=grid[0][0];
        while(!pq.empty()){
            auto [dist,it] = pq.top();pq.pop();
            int x = it.first, y=it.second;
            for(auto [dx,dy]:dirs){
                int nx=x+dx,ny=y+dy;
                if(nx<n&&ny<n&&nx>=0&&ny>=0){
                    int nidx = nx*n+ny;
                    if(minVal[nidx]==INT_MAX || max(dist,grid[nx][ny])<minVal[nidx]){
                        minVal[nidx] = max(dist,grid[nx][ny]);
                        pq.push({minVal[nidx],{nx,ny}});
                    }
                }
            }
        }
        int idx = (n-1)*n+n-1;
        return minVal[idx];
    }
};
