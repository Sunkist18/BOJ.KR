#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pii;

string a, b;

bool solve() {
    cin >> a >> b;
    int a_i = 0, b_i = 0;
    for (auto c : a) a_i += c == '1';
    for (auto c : b) b_i += c == '1';

    return (a_i >= b_i or a_i % 2 and a_i + 1 == b_i);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    cout << (solve() ? "VICTORY" : "DEFEAT") << '\n';

    return 0;
}