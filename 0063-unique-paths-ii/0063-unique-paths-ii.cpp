class Solution {
public:
 vector<vector<int>> dp;
    int fun(int x, int y, vector<vector<int>>& grid){
        if(grid[x][y]==1) return 0;
        if(x==0 && y==0) return 1;
        if(dp[x][y]!=-1) return dp[x][y];
        int ans = 0;
        if(x>0) ans += fun(x-1, y, grid);
        if(y>0) ans += fun(x, y-1, grid);
        return dp[x][y] = ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();   
        dp.resize(m, vector<int>(n, -1));
        return fun(m-1, n-1, grid);
    }

};