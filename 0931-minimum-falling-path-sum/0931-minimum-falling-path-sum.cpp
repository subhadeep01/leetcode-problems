class Solution {
public:
    int rec(int row, int col, int n, int m, vector<vector<int>> &matrix,vector<vector<int>> &dp)
{
    if(row>=n || col>=m || col<0) return INT_MAX;
    if(row==n-1) return matrix[row][col];
    if(dp[row][col]!=-1) return dp[row][col];
    return dp[row][col]=matrix[row][col]+min(rec(row+1,col-1,n,m,matrix,dp),min(rec(row+1,col,n,m,matrix,dp),rec(row+1,col+1,n,m,matrix,dp)));
    
}
    int minFallingPathSum(vector<vector<int>>& matrix) {
           int n=matrix.size();
    int m=matrix[0].size();
    vector<vector<int>>dp(n+2,vector<int>(m+2,-1));
    int ans=INT_MAX;
    for(int i=0;i<m;i++)
    ans=min(ans, rec(0,i,n,m,matrix,dp));
    return ans;
    }
};