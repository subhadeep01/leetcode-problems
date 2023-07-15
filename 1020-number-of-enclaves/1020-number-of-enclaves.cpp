class Solution {
public:
    void dfs(int i, int j, int n ,int m, vector<vector<int>>&grid, vector<vector<int>>&vis)
    {
        vis[i][j]=1;
        
         int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};

    for (int k = 0; k < 4; k++) {
        int nr = i + dx[k];
        int nc = j + dy[k];
        if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[i][j]==1 && vis[nr][nc] == 0) {
            dfs(nr, nc, n,m,grid, vis);
        }
    }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((i==0 || j==0 || i==n-1 || j==m-1 ) && grid[i][j]==1 && !vis[i][j])
                {
                    dfs(i,j,n,m,grid,vis);
                }
            }
        }
        int c=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && vis[i][j]==0)
                    c++;
            }
        }
        return c;
    }
};