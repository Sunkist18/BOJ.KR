#include <bits/stdc++.h>

#define int long long
#define VER 0
#define HOR 1
#define CRO 2

using namespace std;
typedef pair<int, int> pii;

int n;
bool field[16][16];
int dp[16][16][3];

bool in_range(int x, int y) {
    return (0 <= x and x < n and 0 <= y and y < n) and (field[y][x] == 0);
}

bool can_move(int x, int y, int angle) {
    if (angle == CRO) return in_range(x + 1, y + 1) and in_range(x, y + 1) and in_range(x + 1, y);
    if (angle == VER) return in_range(x, y + 1);
    if (angle == HOR) return in_range(x + 1, y);
    return false;
}

int get_dp(int x, int y, int shape) {
    if (dp[y][x][shape] != -1) return dp[y][x][shape];
    if (x == n - 1 and y == n - 1) return 1;
    if (!in_range(x, y)) return 0;
    int ret = 0;
    if (shape == HOR) {
        if (can_move(x, y, HOR)) ret += get_dp(x + 1, y, HOR);
        if (can_move(x, y, CRO)) ret += get_dp(x + 1, y + 1, CRO);
    } else if (shape == VER) {
        if (can_move(x, y, VER)) ret += get_dp(x, y + 1, VER);
        if (can_move(x, y, CRO)) ret += get_dp(x + 1, y + 1, CRO);
    } else {
        if (can_move(x, y, VER)) ret += get_dp(x, y + 1, VER);
        if (can_move(x, y, HOR)) ret += get_dp(x + 1, y, HOR);
        if (can_move(x, y, CRO)) ret += get_dp(x + 1, y + 1, CRO);
    }
    return dp[y][x][shape] = ret;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 3; k++) dp[i][j][k] = -1;
            cin >> field[i][j];
        }

    cout << get_dp(1, 0, HOR) << '\n';
    return 0;
}