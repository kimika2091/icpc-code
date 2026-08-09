#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int INF = 1e9;

vector<int> adj[N], jda[N];
int Min[N];
int n, m;

void sc() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        jda[i].clear();
    }

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        jda[v].push_back(u);
    }
    adj[1].push_back(1);
    jda[1].push_back(1);

    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        Min[i] = INF;
    }
    Min[1] = 1;
    for (int i = 1; i <= n; i++) {
        int minn = INF;
        for (auto j : jda[i]) {
            if (j <= i && Min[j] < INF) {
                minn = min(minn, Min[j]);
            }
        }

        Min[i] = min(Min[i], max(i, minn));

        for (auto j : adj[i]) {
            if (j > i) break;
            int t = max({minn, i, j});
            if (t < Min[j]) {
                Min[j] = t;
                q.push(j);
            }
        }

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto v : adj[u]) {
                if (v > i) break;
                if (Min[v] == INF) {
                    Min[v] = i;
                    q.push(v);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (Min[i] == INF) Min[i] = -1;
        cout << Min[i] << " \n"[i == n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) sc();
    return 0;
}