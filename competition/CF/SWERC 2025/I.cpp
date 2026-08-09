#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<pair<int, int>> adj[105];

int ask(int u, int v) {
    cout << "? " << u << " " << v << endl;
    int res;
    cin >> res;
    if (res == -2) exit(0);
    return res;
}

void build(vector<int> V) {
    if (V.size() <= 1) return;
    map<int, vector<int>> f;
    for (int i = 1; i < V.size(); ++i) {
        int v = V[i];
        int res = ask(V[0] + 1, v);
        adj[V[0]].push_back({v, res});
        adj[v].push_back({V[0], res});
        f[res].push_back(v);
    }
    for (auto const& [res, v] : f) {
        build(v);   
    }
}

void solve() {
    cin >> n;
    if (n == -2) exit(0);
    for (int i = 0; i <= n; ++i) adj[i].clear();
    vector<int> V(n + 1);
    iota(V.begin(), V.end(), 0);
    build(V);
}   

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}