class Solution {
public:
 int solve(int left, int right, vector<vector<int>>&dp, string &s)
 {
            if (dp[left][right] != -1) {
                return dp[left][right];
            }
            
            dp[left][right] = s.size();
            int j = -1;
            
            for (int i = left; i < right; i++) {
                if (s[i] != s[right] && j == -1) {
                    j = i;
                }
                
                if (j != -1) {
                    dp[left][right] = min(dp[left][right], 1 + solve(j, i, dp, s) + solve(i + 1, right, dp, s));
                }
            }
            
            if (j == -1) {
                dp[left][right] = 0;
            }
            
            return dp[left][right];
        }
    int strangePrinter(string s) {
         int n = s.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
         return solve(0, n - 1, dp, s) + 1;
        
    }
};