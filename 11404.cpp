#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pii;

#define GCD(x, y) __gcd(x, y)
#define LCM(x, y) (x * y) / __gcd(x, y)

int V, m;
int field[101][101];

void floyd() {
    for (int k = 1; k <= V; k++) 
        for (int i = 1; i <= V; i++) 
            for (int j = 1; j <= V; j++) 
                field[i][j] = min(field[i][j], field[i][k] + field[k][j]);
}

int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> V >> m;
    for (int i = 1; i <= V; i++) for (int j = 1; j <= V; j++) {
        if (i == j) continue;
        field[i][j] = 987654321;
    }

    while (m--) {
        int here, there, cost;
        cin >> here >> there >> cost;
        if (cost < field[here][there]) field[here][there] = cost;
        // cout << here << ' ' << there << ' ' << cost << '\n';
    }
    floyd();
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            cout << (field[i][j] == 987654321 ? 0 : field[i][j]) << " \n"[j == V];
        }
    }
    return 0;
}
