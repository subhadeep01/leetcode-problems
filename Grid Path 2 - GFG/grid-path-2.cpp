//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  vector<vector<int>> dp;
   const int mod = 1e9+7;
    int fun(int x, int y, vector<vector<int>>& grid){
        if(grid[x][y]==1) return 0;
        if(x==0 && y==0) return 1;
        if(dp[x][y]!=-1) return dp[x][y];
        int ans = 0;
        if(x>0) ans += fun(x-1, y, grid);
        ans%=mod;
        if(y>0) ans += fun(x, y-1, grid);
        ans%=mod;
        return dp[x][y] = ans;
    }
    int totalWays(int n, int m, vector<vector<int>>& grid) {
        // Code here
        dp.resize(n, vector<int>(m, -1));
        if(grid[n-1][m-1]==1)return 0;
        return fun(n-1, m-1, grid);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends