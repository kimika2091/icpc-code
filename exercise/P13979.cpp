#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int b_size, num;
vector <int> L, R, pos;
vector <ll> a, tag, sum;

void build(int n) {
	b_size = sqrt(n);
	num = (n + b_size - 1) / b_size;
	pos.resize(n + 1);
	L.resize(num + 1);
	R.resize(num + 1);
	sum.resize(num + 1);
	tag.resize(num + 1);
	for (int i = 1; i <= num; i++) {
		L[i] = (i - 1) * b_size + 1;
		R[i] = min(i * b_size, n);
		for (int j = L[i]; j <= R[i]; j++) {
			pos[j] = i;
			sum[i] += a[j];
		}
	}
}

void update(int l, int r, ll c) {
	int p = pos[l], q = pos[r];
	if (p == q) {
		for (int i = l; i <= r; i++) a[i] += c, sum[p] += c;
		return;
	}
	for (int i = l; i <= R[p]; i++) a[i] += c, sum[p] += c;
	for (int i = L[q]; i <= r; i++) a[i] += c, sum[q] += c;
	for (int i = p + 1; i <= q - 1; i++) tag[i] += c, sum[i] += c * (R[i] - L[i] + 1);
}

ll query(int l, int r, ll c) {
	int p = pos[l], q = pos[r];
	ll ans = 0;
	if (p == q) {
		for (int i = l; i <= r; i++) ans += a[i] + tag[p];
		ans = (ans % c + c) % c; 
		return ans;
	}
	for (int i = l; i <= R[p]; i++) ans += a[i] + tag[p];
	for (int i = L[q]; i <= r; i++) ans += a[i] + tag[q];
	for (int i = p + 1; i <= q - 1; i++) ans += sum[i];
	ans = (ans % c + c) % c;
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
			cout << query(l, r, c + 1) << '\n';
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