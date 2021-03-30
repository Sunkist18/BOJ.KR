#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int t, n;
vector<int> field;

int find_min(vector<int> &list, int start) {
    int ret = start; int min = 987654321;
    for (int i = start; i < n; i++) {
        if (list[i] < min) {
            min = list[i];
            ret = i;
        }
    }
    return ret;
}

void solve(int tc) {
    cin >> n;
    field.clear();
    field.resize(n);
    for (auto &e : field) cin >> e;
    int result = 0;
    for (int i = 0; i < n - 1; i++) {
        int j = find_min(field, i);
        result += j - i + 1;
        reverse(field.begin() + i, field.begin() + j + 1);
        // for (auto e: field) {
        //     cout << e << ' ';
        // } cout << '\n';
        // cout << i << j << result << '\n';
    }
    cout << "Case #" << tc << ": " << result << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        solve(tc);
    }
    

    return 0;
}