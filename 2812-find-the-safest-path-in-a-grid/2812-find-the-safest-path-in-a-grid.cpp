class Solution {
public:
    int n;

    bool canReach(vector<vector<int>>& dist, int safe) {
        if (dist[0][0] < safe)
            return false;

        vector<vector<int>> vis(n, vector<int>(n, 0));
        queue<pair<int,int>> q;

        q.push({0, 0});
        vis[0][0] = 1;

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == n - 1 && c == n - 1)
                return true;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nc < 0 || nr >= n || nc >= n)
                    continue;

                if (vis[nr][nc])
                    continue;

                if (dist[nr][nc] < safe)
                    continue;

                vis[nr][nc] = 1;
                q.push({nr, nc});
            }
        }

        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int,int>> q;

        // Multi-source BFS from all thieves
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nc < 0 || nr >= n || nc >= n)
                    continue;

                if (dist[nr][nc] != -1)
                    continue;

                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }

        int lo = 0;
        int hi = 2 * n;
        int ans = 0;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (canReach(dist, mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};