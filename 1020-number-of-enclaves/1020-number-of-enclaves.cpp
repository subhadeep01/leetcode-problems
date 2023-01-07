class Solution {
public:
 void dfs(int row,int col, vector<vector<int>>&grid, vector<vector<int>>&vis,int dx[],int dy[])
    {
        vis[row][col]=1;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<4;i++)
        {
            int nr=row+dx[i];
            int nc=col+dy[i];

            if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0 && grid[nr][nc]==1)
            {
                   dfs(nr,nc,grid,vis,dx,dy);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int dx[]={-1,0,+1,0};
        int dy[]={0,+1,0,-1};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((i==0 || j==0 || i==n-1 || j==m-1) && grid[i][j]==1)
                {
                    dfs(i,j,grid,vis,dx,dy);
                }
            }
        }
        int c=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==1)
                grid[i][j]=0;
                
            }
        }
         for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                c++;
            }
        }
        return c;
    }
};