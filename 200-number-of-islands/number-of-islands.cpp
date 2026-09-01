class Solution {
public:

    void dfs(vector<vector<char>>& grid, int r, int c) {

        int m = grid.size();
        int n = grid[0].size();

        if (r < 0 || r >= m ||
            c < 0 || c >= n ||
            grid[r][c] != '1')
            return;

        grid[r][c] = '0';

        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }

    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int islands = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                if (grid[r][c] == '1') {
                    islands++;
                    dfs(grid, r, c);
                }
            }
        }

        return islands;
    }
};