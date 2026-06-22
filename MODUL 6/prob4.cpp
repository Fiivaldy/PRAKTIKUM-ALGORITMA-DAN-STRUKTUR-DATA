#include <iostream>
#include <vector>
using namespace std;

int R, C;
int SR, SC, FR, FC;
int totalPath = 0;

vector<vector<int>> grid;
vector<vector<bool>> visited;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void dfs(int r, int c) {
    if (r == FR && c == FC) {
        totalPath++;
        return;
    }

    visited[r][c] = true;

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
            if (grid[nr][nc] == 0 && !visited[nr][nc]) {
                dfs(nr, nc);
            }
        }
    }

    visited[r][c] = false;
}

int main() {
    cin >> R >> C;

    grid.assign(R, vector<int>(C));
    visited.assign(R, vector<bool>(C, false));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> SR >> SC;
    cin >> FR >> FC;

    dfs(SR, SC);

    cout << totalPath << endl;

    return 0;
}