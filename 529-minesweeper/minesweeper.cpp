class Solution {
public:
    void dfs(vector<vector<char>>& board, int r, int c) {

        int m = board.size();
        int n = board[0].size();

        if (r < 0 || r >= m || c < 0 || c >= n ||
            board[r][c] != 'E')
            return;

        int mines = 0;

        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {

                int nr = r + dr;
                int nc = c + dc;

                if (nr >= 0 && nr < m &&
                    nc >= 0 && nc < n &&
                    board[nr][nc] == 'M') {
                    mines++;
                }
            }
        }

        if (mines > 0) {
            board[r][c] = '0' + mines;
            return;
        }

        board[r][c] = 'B';

        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
                dfs(board, r + dr, c + dc);
            }
        }
    }

    vector<vector<char>> updateBoard(
        vector<vector<char>>& board,
        vector<int>& click) {

        int r = click[0];
        int c = click[1];

        if (board[r][c] == 'M') {
            board[r][c] = 'X';
            return board;
        }

        dfs(board, r, c);
        return board;
    }
};