#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pii;

int t, n, c;

bool verify(int num, int cost) {
    return num - 1 <= cost and cost < num * (num + 1) / 2;
}

void print(int cs, const vector<int>& a) {
    cout << "Case #" << cs << ": ";
    if (!a.size()) {
        cout << "IMPOSSIBLE" << '\n';
        return;
    }
    for (auto e : a) cout << e << ' ';
    cout << '\n';
}

vector<int> mknum() {
    vector<int> nums(n - 1, 1);
    int k = c - (n - 1);
    for (int cap = n - 1; cap > 0; cap--) {
        int index = (n - 1) - cap;
        if (k - cap >= 0) {
            k -= cap;
            nums[index] += cap;
        } else {
            nums[index] += k;
            k = 0;
        }
        if (k == 0) break;
    }
    return nums;
}

vector<int> solve() {
    vector<int> ret;
    cin >> n >> c;
    if (!verify(n, c)) return ret;
    for (int i = 1; i <= n; i++) ret.emplace_back(i);
    
    vector<int> nums = mknum();

    int left = 0; int right = n;
    bool r_button = true;
    for (auto range : nums) {
        if (r_button) reverse(ret.begin() + right - range, ret.begin() + right);
        else reverse(ret.begin() + left, ret.begin() + left + range);
        right -= r_button;
        left += !r_button;
        r_button = !r_button;
    }
    return ret;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> t;
    for (int i = 1; i <= t; i++) print(i, solve());

    return 0;
}