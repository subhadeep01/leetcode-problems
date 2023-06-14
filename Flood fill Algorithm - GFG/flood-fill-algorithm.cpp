//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
void dfs(int row, int col,vector<vector<int>>& image, int newColor, int color,vector<vector<int>>& vis, int dx[], int dy[]) {
    vis[row][col]=newColor;
    int n=image.size();
    int m=image[0].size();

    for(int i=0;i<4;i++)
    {
        int nr=row+dx[i];
        int nc=col+dy[i];
        if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]!=newColor && image[nr][nc]==color)
        {
            dfs(nr,nc,image,newColor,color,vis,dx,dy);
        }
    }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
     int n=image.size();
     int m=image[0].size();
     int color=image[sr][sc];
     vector<vector<int>>vis=image;

    int dx[]={-1,0,+1,0};
    int dy[]={0,+1,0,-1};
     dfs(sr,sc,image,newColor,color,vis,dx,dy);
     return vis;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends