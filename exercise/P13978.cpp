#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int b_size, num;
vector <int> L, R, pos;
vector <ll> a, tag;
vector <vector<ll>> sorted;

void build(int n) {
	b_size = sqrt(n);
	num = (n + b_size - 1) / b_size;
	pos.resize(n + 1);
	L.resize(num + 1);
	R.resize(num + 1);
	tag.resize(num + 1);
	sorted.resize(num + 1);
	for (int i = 1; i <= num; i++) {
		L[i] = (i - 1) * b_size + 1;
		R[i] = min(i * b_size, n);
		for (int j = L[i]; j <= R[i]; j++) {
			pos[j] = i;
			sorted[i].push_back(a[j]);
		}
		sort(sorted[i].begin(), sorted[i].end());
	}
}

void rebuild(int p) {
	sorted[p].clear();
	for (int i = L[p]; i <= R[p]; i++) sorted[p].push_back(a[i]);
	sort(sorted[p].begin(), sorted[p].end());
}

void update(int l, int r, ll c) {
	int p = pos[l], q = pos[r];
	if (p == q) {
		for (int i = l; i <= r; i++) a[i] += c;
		rebuild(p);
		return;
	}
	for (int i = l; i <= R[p]; i++) a[i] += c;
	rebuild(p);
	for (int i = L[q]; i <= r; i++) a[i] += c;
	rebuild(q);
	for (int i = p + 1; i <= q - 1; i++) tag[i] += c;
}

ll query(int l, int r, ll c) {
	int p = pos[l], q = pos[r];
	ll ans = -9e18;
	if (p == q) {
		for (int i = l; i <= r; i++) if (a[i] + tag[p] < c) ans = max(ans, a[i] + tag[p]);
		if (ans == -9e18) ans = -1;
		return ans;
	}
	for (int i = l; i <= R[p]; i++) if (a[i] + tag[p] < c) ans = max(ans, a[i] + tag[p]);
	for (int i = L[q]; i <= r; i++) if (a[i] + tag[q] < c) ans = max(ans, a[i] + tag[q]);
	for (int i = p + 1; i <= q - 1; i++) {
		int t = lower_bound(sorted[i].begin(), sorted[i].end(), c - tag[i]) - sorted[i].begin() - 1;
		if (t != -1) ans = max(ans, sorted[i][t] + tag[i]);
	}
	if (ans == -9e18) ans = -1;
	return ans;
}

void solve() {
	int n;
	cin >> n;
	a.resize(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(n);
	for (int i = 1; i <= n; i++) {
		int opt, l, r;
		ll c;		
		cin >> opt >> l >> r >> c;
		if (opt == 0) {
			update(l, r, c);
		}
		else {
			cout << query(l, r, c) << '\n';
		}
	}
}

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	int T = 1;
	// cin >> T;
	while(T--) {
		solve();
	}
	return 0; 
}