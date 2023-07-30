class Solution {
public:
     int solve(int i, int j, vector<vector<int>>&dp, string &s)
     {
         if(i==j) return 1;
         
         if(dp[i][j]!=-1) return dp[i][j];
         
         int ans=INT_MAX;
         
         for(int k=i;k<j;k++)
         {
             ans = min(ans,solve(i,k,dp,s) + solve(k+1,j,dp,s));
         }
         
         return dp[i][j]=((s[i]==s[j])?ans-1:ans);
               
     }
    int strangePrinter(string s) 
    {
         int n = s.size();
         vector<vector<int>>dp(n, vector<int>(n, -1));
         return solve(0, n - 1, dp, s);
        
    }
};