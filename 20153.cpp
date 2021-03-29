#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pii;

#define GCD(x, y) __gcd(x, y)
#define LCM(x, y) (x * y) / __gcd(x, y)

int n;
vector<int> field;
int cnt[25];

int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    field.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> field[i];
        for (int j = 0; 1 << j <= field[i]; j += 1) {
            cnt[j + 1] += (field[i] & 1 << j ? 1 :0);
        }
    }
    int result = 0;
    for (int i = 0; i < 25; i++) {
        if (cnt[i + 1] % 2 == 1) {
            result += 1 << i;
        }
    }
    for (auto number : field) {
        int var = 0;
        for (int i = 0; i < 25; i++) {
            if (cnt[i + 1] % 2 == 0 and (number & (1 << i)) or
                cnt[i + 1] % 2 == 1 and !(number & (1 << i))) {
                var += 1 << i;
            }
        }
        result = max(result, var);
    }
    cout << result << result;
    return 0;
}