class Solution {
public:
    int integerBreak(int n) {
        vector<int>dp(101,0);
        dp[1]=1;
        dp[2]=1;
        dp[3]=2;
        for(int i=4;i<=n;i++)
        {
            for(int j=1;j<i;j++)
            {
                int x = j;
                int y = i-j;
                dp[i]=max({dp[i],x*y,x*dp[y],y*dp[x],dp[x]*dp[y]});
            }
        }
        return dp[n];
    }
};