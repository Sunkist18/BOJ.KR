#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pii;

int t, x, y;

int dp[2000][2];
void solve(int c) {
    string line;
    cin >> x >> y >> line;
    for (int i = 0; i < line.size(); i++) {
        dp[i][0] = (line[i] == 'C' ? 0 : 987654321);
        dp[i][1] = (line[i] == 'J' ? 0 : 987654321);
        if (line[i] == '?') dp[i][0] = dp[i][1] = 0;
        if (i == 0) continue;
        dp[i][0] += min(dp[i - 1][1] + y, dp[i - 1][0]);
        dp[i][1] += min(dp[i - 1][0] + x, dp[i - 1][1]);
    }
    cout << "Case #" << c << ": " << min(dp[line.size() - 1][0], dp[line.size() - 1][1]) << '\n';
} 

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> t;
    for (int i = 1; i <= t; i++) solve(i);

    return 0;
}