class Solution {
public:
     int f(int amount, vector<int>&coins, int n, vector<int>&dp)
    {
        if(amount==0)return 0;
        if(dp[amount]!=-1)return dp[amount];
        int res=2e9;
        int mn=2e9;
        for(int i=0;i<n;i++)
        {
            if(coins[i]<=amount)
            mn=min(mn,f(amount-coins[i],coins,n,dp));
            res=min(res,mn);
        }
        return dp[amount]=1+res;
    }
 
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        int res=f(amount,coins,coins.size(),dp);
        if(res>1e4)return -1;
        return res;
    }
};