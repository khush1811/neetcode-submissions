class Solution {
private:
    bool recurse(string& s, string& p, int sidx, int pidx,
                 vector<vector<int>>& dp) {

        if(sidx == s.size() && pidx == p.size())
            return true;

        if(pidx == p.size())
            return false;

        if(dp[sidx][pidx] != -1)
            return dp[sidx][pidx];

        // String is exhausted
        if(sidx == s.size()) {
            if(pidx + 1 < p.size() && p[pidx + 1] == '*') {
                return dp[sidx][pidx] =
                    recurse(s, p, sidx, pidx + 2, dp);
            }

            return dp[sidx][pidx] = false;
        }

        bool match = (p[pidx] == s[sidx] || p[pidx] == '.');
        if(pidx + 1 < p.size() && p[pidx + 1] == '*') {

            bool take = false;
            bool skip = false;
            if(match) {
                take = recurse(s, p, sidx + 1, pidx, dp);
            }
            skip = recurse(s, p, sidx, pidx + 2, dp);

            return dp[sidx][pidx] = take || skip;
        }
        if(match) {
            return dp[sidx][pidx] =
                recurse(s, p, sidx + 1, pidx + 1, dp);
        }

        return dp[sidx][pidx] = false;
    }

public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(
            s.size() + 1,
            vector<int>(p.size() + 1, -1)
        );

        return recurse(s, p, 0, 0, dp);
    }
};