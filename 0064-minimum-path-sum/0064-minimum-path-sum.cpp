class Solution {
public:
//     int f(vector<vector<int>>&grid,int m, int n,vector<vector<int>>&dp)
//     {
//         if(m<0 || n<0) return INT_MAX;
//         if(m==0 && n==0)return dp[m][n]=grid[m][n];
//         if(n==0)
//         {
//         int t;
//         if(dp[m-1][0]!=-1)
//         t=dp[m-1][0];
//         else
//         t=f(grid,m-1,0,dp);
//         return dp[m][0]=grid[m][0]+t;
//         }
//         if(m==0)
//         {
//         int t;
//         if(dp[0][n-1]!=-1)
//         t=dp[0][n-1];
//         else
//         t=f(grid,0,n-1,dp);
//         return dp[0][n]=grid[0][n]+t;    
//         }
//         if(dp[m][n]!=-1)
//         return dp[m][n];
//         int ans1,ans2,ans3;
//         if(dp[m-1][n]!=-1)
//         ans1=dp[m-1][n];
//         else
//         ans1=f(grid,m-1,n,dp);
//         if(dp[m][n-1]!=-1)
//         ans2=dp[m][n-1];
//         else
//         ans2=f(grid,m,n-1,dp);
//         return dp[m][n]=grid[m][n]+min(ans1,ans2);
        
        
//     }
    int rec(int i, int j, int n, int m, vector<vector<int>> &grid,vector<vector<int>> &dp)
{
   if(i<0 || j<0) return 1e9;
  if(i==0 && j==0)   return grid[i][j];
  if(dp[i][j]!=-1)return dp[i][j];
  return dp[i][j]=grid[i][j]+min(rec(i-1,j,n,m,grid,dp),rec(i,j-1,n,m,grid,dp));
}
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n+2, vector<int>(m+2,-1));
       // return f(grid,m-1,n-1,dp);
          return rec(n-1,m-1,n,m,grid,dp);
    }
};