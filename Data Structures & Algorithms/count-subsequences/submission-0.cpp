class Solution {
private:
    int recurse(string& s, string& t, vector<vector<int>>& dp, int sidx, int tidx){
        if(tidx==t.size())return 1;
        if(sidx==s.size())return 0;

        if(dp[sidx][tidx]!=-1)return dp[sidx][tidx];

        int take=0,skip=0;
        if(s[sidx]==t[tidx]){
            take = recurse(s,t,dp,sidx+1,tidx+1);
        }
        skip = recurse(s,t,dp,sidx+1,tidx);
        return dp[sidx][tidx] = take+skip;
    }
public:
    int numDistinct(string s, string t) {
        vector<vector<int>>dp(s.size(),vector<int>(t.size(),-1));
        return recurse(s,t,dp,0,0);
    }
};
