class Solution {
public:
    int mod = 1e9 + 7;

    int solve(int s, int e, int k, vector<vector<int>>& dp) {
        if (k == 0) {
            if (s == e) return 1;
            return 0;
        }
        // if (dp[s][k] != -1) return dp[s][k]; //since s may be negativ so we do not direct use s as a index
        
        if(dp[s+999][k] != -1) return dp[s+999][k];

        long long num = (solve(s + 1, e, k - 1, dp) + solve(s - 1, e, k - 1, dp)) % mod;
        dp[s+999][k] = num;

        return num;
    }

    int numberOfWays(int startPos, int endPos, int k) {
        // Use dynamic sizes for dp
        vector<vector<int>> dp(3000, vector<int>(k + 1, -1));   //k=1000 ans s =1 then range = -999to1001 if k=1000 and s =1000 then range = 0 to 2000, hence we are adding 999 to make the s positive so we take 3000 as a dp size;
        return solve(startPos, endPos, k, dp);
    }
};
