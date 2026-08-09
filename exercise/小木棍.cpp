#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool dfs (const vector <int> &a, ll status, int cur, int n, int L, int start) {
	if (status == (1LL << n) - 1) return true;
	if (cur == L) return dfs(a, status, 0, n, L, 0);
	int lst = -1;
	for (int i = start; i < n; i++) {
		if (status >> i & 1 || cur + a[i] > L || a[i] == lst) continue;	
		if(dfs(a, status | (1LL << i), cur + a[i], n, L, i + 1)) return true;
		
		lst = a[i];
		if (cur == 0 || a[i] + cur == L) return false; 
	}
	return false;
}

void solve() {
	int n;
	cin >> n;
	vector <int> a(n);
	int sum = 0;
	for (auto &x : a) cin >> x, sum += x;
	sort(a.begin(), a.end(), greater<int>());
	for (int i = a[0]; i <= sum / 2; i++) {
		if (sum % i != 0) continue;
		if (dfs(a, 0, 0, n, i, 0)) {
			cout << i << '\n';
			return;
		}
	}
	cout << sum << '\n';
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