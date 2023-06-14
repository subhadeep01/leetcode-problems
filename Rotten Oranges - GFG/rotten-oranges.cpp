//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    visited[i][j]=1;
                }
            }
        }
        int dx[]={-1,0,+1,0};
        int dy[]={0,-1,0,+1};
        int tm=0;
        while(!q.empty())
        {
            auto node= q.front();
            int row = node.first.first;
            int col = node.first.second;
            int t = node.second; 
            tm=max(tm,t);
            q.pop();
            for(int i=0;i<4;i++)
            {
                int x=row+dx[i];
                int y=col+dy[i];
                if(x>=0 && x<n && y>=0 && y<m && !visited[x][y] && grid[x][y]==1)
                {
                    visited[x][y]=1;
                    q.push({{x,y},t+1});
                    grid[x][y]=2;
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
        return tm;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends