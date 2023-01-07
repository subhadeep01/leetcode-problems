class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int c=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                c++;
            }
        }
        if(c==0) return 0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        int t=-1;
        int x=0;
        while(!q.empty())
        {
            if(x==0){
            x=q.size();
            t++;
            }
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            x--;
            int dx[]={-1,0,+1,0};
            int dy[]={0,+1,0,-1};
            for(int i=0;i<4;i++)
            {
                int nr=row+dx[i];
                int nc=col+dy[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]==1)
                {
                    vis[nr][nc]=1;
                    grid[nr][nc]=2;
                    q.push({nr,nc});
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                return -1;
            }
        }
        return t;
    }
};