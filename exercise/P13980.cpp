#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int b_size, num;
vector <int> L, R, pos;
vector <ll> a, sum;

void build(int n) {
	b_size = sqrt(n);
	num = (n + b_size - 1) / b_size;
	pos.resize(n + 1);
	L.resize(num + 1);
	R.resize(num + 1);
	sum.resize(num + 1);
	for (int i = 1; i <= num; i++) {
		L[i] = (i - 1) * b_size + 1;
		R[i] = min(i * b_size, n);
		for (int j = L[i]; j <= R[i]; j++) {
			pos[j] = i;
			sum[i] += a[j];
		}
	}
}

void update(int l, int r) {
	int p = pos[l], q = pos[r];
	if (p == q) {
		for (int i = l; i <= r; i++) sum[p] -= a[i], a[i] = sqrt(a[i]), sum[p] += a[i];
		return;
	}
	for (int i = l; i <= R[p]; i++) sum[p] -= a[i], a[i] = sqrt(a[i]), sum[p] += a[i];
	for (int i = L[q]; i <= r; i++) sum[q] -= a[i], a[i] = sqrt(a[i]), sum[q] += a[i];
	for (int i = p + 1; i <= q - 1; i++) {
		if (sum[i] <= R[i] - L[i] + 1) continue;
		sum[i] = 0;
		for (int j = L[i]; j <= R[i]; j++) {
			a[j] = sqrt(a[j]);
			sum[i] += a[j];
		}
	}
}

ll query(int l, int r) {
	int p = pos[l], q = pos[r];
	ll ans = 0;
	if (p == q) {
		for (int i = l; i <= r; i++) ans += a[i];
		return ans;
	}
	for (int i = l; i <= R[p]; i++) ans += a[i];
	for (int i = L[q]; i <= r; i++) ans += a[i];
	for (int i = p + 1; i <= q - 1; i++) ans += sum[i];
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
		cin >> opt >> l >> r;
		if (opt == 0) {
			update(l, r);
		}
		else {
			cout << query(l, r) << '\n';
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