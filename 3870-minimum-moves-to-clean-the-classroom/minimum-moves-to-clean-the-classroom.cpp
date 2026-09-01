class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        int sr, sc;
        int cnt = 0;

        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    id[i][j] = cnt++;
                }
            }
        }

        int all = (1 << cnt) - 1;

        // visited[r][c][energy][mask]
        vector visited(
            m,
            vector(
                n,
                vector(
                    energy + 1,
                    vector<char>(1 << cnt, false)
                )
            )
        );

        queue<array<int, 5>> q;

        q.push({sr, sc, energy, 0, 0});
        visited[sr][sc][energy][0] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            auto [r, c, e, mask, steps] = q.front();
            q.pop();

            if (mask == all)
                return steps;

            for (int d = 0; d < 4; d++) {

                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr < 0 || nr >= m ||
                    nc < 0 || nc >= n ||
                    classroom[nr][nc] == 'X')
                    continue;

                if (e == 0)
                    continue;

                int ne = e - 1;
                int nmask = mask;

                // Collect litter
                if (classroom[nr][nc] == 'L') {
                    nmask |= (1 << id[nr][nc]);
                }

                // Recharge
                if (classroom[nr][nc] == 'R') {
                    ne = energy;
                }

                if (!visited[nr][nc][ne][nmask]) {

                    visited[nr][nc][ne][nmask] = true;

                    q.push({
                        nr,
                        nc,
                        ne,
                        nmask,
                        steps + 1
                    });
                }
            }
        }

        return -1;
    }
};