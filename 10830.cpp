#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pii;

// 단위 행렬 one을 정의한다. 매트릭스 A에 대해 A^{0} = one 이다.
vector<vector<int>> one(5, vector<int> (5));

// 행렬 a와 b를 곱하는 함수이다.
vector<vector<int>> matrix_multi(vector<vector<int>> &a, vector<vector<int>> &b) {
    int n = a.size();
    vector<vector<int>> c(n, vector<int>(n));

    // 행렬 곱을 코드화 한 결과이다.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
            c[i][j] %= 1000;
        }
    }
    return c;
}

vector<vector<int>> matrix_power(vector<vector<int>> &a, int b) {
    if (b == 0) return one;
    else if (b == 1) return a;
    else if (b % 2 == 0) {
        vector<vector<int>> temp = matrix_power(a, b / 2);
        return matrix_multi(temp, temp);
    } else {
        vector<vector<int>> temp = matrix_power(a, b - 1);
        return matrix_multi(temp, a);
    }
}

int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, b;
    cin >> n >> b;

    vector<vector<int>> a(n, vector<int>(n));
    vector<vector<int>> answer(n, vector<int>(n));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        } one[i][i] = 1;
    }

    answer = matrix_power(a, b);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << answer[i][j] % 1000 << ' ';
        }
        cout << '\n';
    }

    return 0;
}
