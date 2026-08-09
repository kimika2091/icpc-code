#include<bits/stdc++.h>
using namespace std;
using ll = long long;


void solve() {
	int n;
	cin >> n;
	vector <vector<int>> bucket(n + 1);
	for (int i = 0; i < n; i++) {
		int v, s;
		cin >> v >> s;
		bucket[s].push_back(v); 
	}
	ll sum = 0, ans = 0;
	priority_queue <int, vector<int>, greater<int>> q;
	for (int i = n; i >= 1; i--) {
		for (int v : bucket[i]) q.push(v), sum += v;
		while (q.size() > i) sum -= q.top(), q.pop();
		ans = max(ans, sum);
	}
	cout << ans << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int T = 1;
	// cin >> T;
	while(T--) {
	    solve();
	}
	return 0; 
}