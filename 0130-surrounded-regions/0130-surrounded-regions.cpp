class Solution {
public:
    void dfs(int row,int col, vector<vector<char>>&board, vector<vector<int>>&vis,int dx[],int dy[])
    {
        vis[row][col]=1;
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<4;i++)
        {
            int nr=row+dx[i];
            int nc=col+dy[i];

            if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0 && board[nr][nc]=='O')
            {
                   dfs(nr,nc,board,vis,dx,dy);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int dx[]={-1,0,+1,0};
        int dy[]={0,+1,0,-1};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((i==0 || j==0 || i==n-1 || j==m-1) && board[i][j]=='O')
                {
                    dfs(i,j,board,vis,dx,dy);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==1)
                board[i][j]='O';
                else
                board[i][j]='X';
            }
        }
    }
};