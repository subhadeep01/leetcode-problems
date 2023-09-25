class Solution {
public:
    const int mod = 1000000007;
    int countOrders(int n) {
        vector<long long>dp(n+1,0);
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            long long permutations = (2*i-1)*i;
            dp[i]=(dp[i-1]%mod * permutations%mod)%mod;
        }
        return (int)dp[n];
    }
};