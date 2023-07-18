class Solution {
public:
 int f(int i, int j, int n, int m, vector<vector<int>>&mat, vector<vector<int>>&dp)
{
	if(i<0 || j<0 || i>=n || j>=m) return 0;
	if(j==m-1)
	{
		return 1;
	}
	if(dp[i][j]!=-1) return dp[i][j];
    int temp=0;
	for(int row=-1;row<=1;row++)
	{
        if(j+1<m && i+row>=0 && i+row<n && mat[i+row][j+1]>mat[i][j])
		temp=max(temp,f(i+row,j+1,n,m,mat,dp));
	}
	return dp[i][j]=1+temp;
}
    int maxMoves(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<n;i++)
        {
            ans=max(ans,f(i,0,n,m,grid,dp));
        }
        return ans-1;
    }
};