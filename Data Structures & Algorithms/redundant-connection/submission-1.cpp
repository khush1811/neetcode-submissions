class Solution {
private:
    int find(int u, vector<int>& par){
        if(par[u]==u)return par[u];
        return find(par[u],par);
    }
    void unite(int u, int v, vector<int>& par){
        int pu = find(u,par);
        int pv = find(v,par);
        if(pu!=pv){
            par[pu]=pv;
        }
        return;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>par(n+1);
        for(int i=1;i<=n;i++)par[i]=i;
        for(auto &edge:edges){
            int p0 = find(edge[0],par);
            int p1 = find(edge[1],par);
            if(p0!=p1){
                unite(edge[0],edge[1],par);
            }
            else{
                return edge;
            }
        }
    }
};
