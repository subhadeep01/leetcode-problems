class Solution {
public:
    
    int countVowelStrings(int n) {
        vector<vector<int>>dp(n+2,vector<int>(6,0));
        dp[0][5]=1;
        for(int i=1;i<=n+1;i++)
        {
            dp[i][5]=1;
            for(int k=4;k>=1;k--)
            {
                for(int j=5;j>=k;j--)
                dp[i][k]+=dp[i-1][j];
            }
        }
        return dp[n+1][1];
    }
};