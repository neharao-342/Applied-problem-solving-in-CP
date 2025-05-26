#include <bits/stdc++.h>
using namespace std;

string path;
int n = 48;
int dx[4] = {0, 0, -1, 1};  // D, U, L, R
int dy[4] = {1, -1, 0, 0};
char moves[4] = {'D', 'U', 'L', 'R'};

// Memoization table: dp[i][x][y]
// -1 means not calculated yet
long long dp[49][8][8];

long long dfs(int i, int x, int y) {
    if (x < 0 || x > 7 || y < 0 || y > 7) return 0; // outside grid
    if (i == n) return (x == 7 && y == 0) ? 1 : 0;

    long long &res = dp[i][x][y];
    if (res != -1) return res;
    res = 0;

    char c = path[i];
    if (c == '?') {
        // try all moves
        for (int m = 0; m < 4; m++) {
            int nx = x + dx[m];
            int ny = y + dy[m];
            res += dfs(i + 1, nx, ny);
        }
    } else {
        // move according to the character
        for (int m = 0; m < 4; m++) {
            if (moves[m] == c) {
                int nx = x + dx[m];
                int ny = y + dy[m];
                res += dfs(i + 1, nx, ny);
                break;
            }
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> path;
    memset(dp, -1, sizeof(dp));

    cout << dfs(0, 0, 0) << "\n";

    return 0;
}
