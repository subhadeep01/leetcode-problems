class Solution {
public:
  bool isMatch(string s, string p) {
    // The size of s and p
    int m = s.size(), n = p.size();

    // A table to store the results of subproblems
    // dp[i][j] means whether s[0..i-1] matches p[0..j-1]
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

    // Base case: empty s matches empty p
    dp[0][0] = true;

    // Base case: empty s matches p that has only stars
    for (int j = 1; j <= n; j++) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 2];
        }
    }

    // Fill the table from top to bottom and left to right
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            // If the current character of p is a dot or matches the current character of s
            if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            // If the current character of p is a star
            else if (p[j - 1] == '*') {
                // We can either ignore it or repeat the preceding element
                dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && (p[j - 2] == '.' || p[j - 2] == s[i - 1]));
            }
        }
    }

    // Return the final result
    return dp[m][n];
}

};