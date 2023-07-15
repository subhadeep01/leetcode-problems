class Solution
{
    public:
void dfs(vector<vector<char>>& board, vector<vector<int>>& vis, int i, int j, int n, int m) {
    vis[i][j] = 1;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};

    for (int k = 0; k < 4; k++) {
        int nr = i + dx[k];
        int nc = j + dy[k];
        if (nr >= 0 && nr < n && nc >= 0 && nc < m && board[nr][nc] == 'O' && vis[nr][nc] == 0) {
            dfs(board, vis, nr, nc, n, m);
        }
    }
}

void solve(vector<vector<char>>& board) {
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && board[i][j] == 'O') {
                dfs(board, vis, i, j, n, m);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j] == 1)
                board[i][j] = 'O';
            else
                board[i][j] = 'X';
        }
    }
}

};