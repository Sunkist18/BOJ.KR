#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pii;

int vertex, edge;

int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> vertex >> edge;
    unordered_map<int, vector<pii>> field;

    // <cost, <<vertex ... >, current_vertex>>
    priority_queue<pair<int, pair<vector<int>, int>>> pq;

    while (edge--) {
        int here, there, cost;
        cin >> here >> there >> cost;
        field[here].emplace_back(there, cost);
    }
    int begin_v, end_v;
    cin >> begin_v >> end_v;

    vector<pair<int, vector<int>>> dist;
    dist.resize(vertex + 1);
    for (int i = 1; i <= vertex; i++) dist[i] = {987654321, {}};

    dist[begin_v] = {0, {begin_v}};
    pq.push({0, {{begin_v}, begin_v}});

    while (!pq.empty()) {
        auto zip = pq.top();
        int cost = -zip.first;
        vector<int> travel = zip.second.first;
        int here = zip.second.second;
        pq.pop();
        
        for (auto e : field[here]) {
            int there, move_cost;
            tie(there, move_cost) = e;

            if (cost + move_cost < dist[there].first) {
                dist[there].first = cost + move_cost;
                dist[there].second = travel;
                dist[there].second.push_back(there);
                pq.push({-dist[there].first, {dist[there].second, there}});
            }
        }
    }
    cout << dist[end_v].first << '\n';
    cout << dist[end_v].second.size() << '\n';
    for (auto e : dist[end_v].second) cout << e << ' ';
    return 0;
}
