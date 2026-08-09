#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector <vector<int>> g(n + 1); 
    vector <int> deg(n + 1);
    for (int i = 1; i <= n; i += 2) {
        for (int j = i * 3; j <= n; j += i * 2) {
            g[j].push_back(i);
            deg[i]++;
        }
    }
    queue <int> q;
    for (int i = 1; i <= n; i += 2) if (deg[i] == 0) q.push(i);
    vector <int> mul(n + 1, 1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto &v : g[u]) {
            mul[v] = max(mul[v], mul[u] * 2);
            deg[v]--;
            if (deg[v] == 0) q.push(v);
        }
    }
    vector <int> ans;
    for (int i = 1; i <= n; i += 2) ans.push_back(i * mul[i]);
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto &x : ans) cout << x << ' ';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int T = 1;
	cin >> T;
	while(T--) {
	    solve();
	}
	return 0; 
}
/*

*/