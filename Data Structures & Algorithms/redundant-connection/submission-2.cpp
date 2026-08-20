class Solution {
private:
    int find(int u, vector<int>& par) {
        if (par[u] == u)
            return u;

        return par[u] = find(par[u], par);
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<int> par(n + 1);

        for (int i = 1; i <= n; i++)
            par[i] = i;

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            int pu = find(u, par);
            int pv = find(v, par);

            if (pu == pv) {
                return edge;
            }

            par[pu] = pv;
        }

        return {};
    }
};