#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve () {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> e(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
    }
    vector<int> dis(n + 1, n + 1);
    auto bfs = [&](){
        vector<bool> vis(n + 1);
        priority_queue<int, vector<int>, greater<int>> q;
        q.push(1);
        dis[1] = 1;
        while (!q.empty()) {
            int u = q.top();
            q.pop();
            if (vis[u]) continue;
            vis[u] = 1;
            for (int v : e[u]) {
                if (max(dis[u], v) < dis[v]) {
                    dis[v] = max(dis[u], v);
                    q.push(v);
                }
            }
        }
    };
    bfs();
    for (int i = 1; i <= n; i++) {
        cout << (dis[i] == n + 1 ? -1 : dis[i]) << ' ';
    }
    cout << '\n';
}

int main () {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}