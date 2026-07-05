class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {

        int n = board.size();
        const int MOD = 1e9 + 7;

        vector<vector<int>> score(n, vector<int>(n, -1));
        vector<vector<long long>> ways(n, vector<long long>(n, 0));

        score[0][0] = 0;
        ways[0][0] = 1;

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < n; j++) {

                if(board[i][j] == 'X')
                    continue;

                if(i == 0 && j == 0)
                    continue;

                int best = -1;
                long long cnt = 0;

                vector<pair<int,int>> prev = {
                    {i-1,j},
                    {i,j-1},
                    {i-1,j-1}
                };

                for(auto &[r,c] : prev) {

                    if(r < 0 || c < 0)
                        continue;

                    if(score[r][c] == -1)
                        continue;

                    if(score[r][c] > best) {
                        best = score[r][c];
                        cnt = ways[r][c];
                    }
                    else if(score[r][c] == best) {
                        cnt = (cnt + ways[r][c]) % MOD;
                    }
                }

                if(best == -1)
                    continue;

                int val = 0;

                if(board[i][j] != 'S' && board[i][j] != 'E')
                    val = board[i][j] - '0';

                score[i][j] = best + val;
                ways[i][j] = cnt % MOD;
            }
        }

        if(score[n-1][n-1] == -1)
            return {0,0};

        return {score[n-1][n-1], (int)(ways[n-1][n-1] % MOD)};
    }
};