#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pii;

int n, m, r;
int t;
int a, b, l;

vector<int> point;
int field[100][100];

int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> r;
    point.resize(n);
    for (auto &e : point) cin >> e;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if(i != j) field[i][j] = 987654321;
    while (r--) {
        cin >> a >> b >> l;
        a -= 1; b -= 1;
        field[a][b] = l;
        field[b][a] = l;
    }

    for (int via = 0; via < n; via++) {
        for (int from = 0; from < n; from++) {
            if (field[from][via] == 987654321) continue;
            for (int to = 0; to < n; to++) {
                field[from][to] = min(field[from][to], field[from][via] + field[via][to]);
            }
        }
    }
    int result = 0;
    for (int i = 0; i < n; i++) {
        int var = 0;
        for (int j = 0; j < n; j++) var += (field[i][j] <= m ? point[j] : 0);
        result = max(result, var);
    }
    cout << result;
    return 0;
}