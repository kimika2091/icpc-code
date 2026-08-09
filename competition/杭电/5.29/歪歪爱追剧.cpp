#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct Segment {
	int l, r;
	Segment(int l, int r) : l(l), r(r) {}
	bool operator < (const Segment &other) const {
		return r < other.r;
	}
};

void solve() {
	int L, n, m;
	cin >> L >> n >> m;
	vector <Segment> segs;
	for (int i = 1; i <= n; i++) {
		int l, r;
		cin >> l >> r;
		segs.emplace_back(l, r);
	}
	vector <int> a(m);
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector <Segment> p;
	for (auto &seg : segs) {
		auto it = lower_bound(a.begin(), a.end(), seg.l);
		if (it != a.end() && *it <= seg.r) p.push_back(seg);
	}
	int k = p.size();
	sort(p.begin(), p.end());
	vector <int> R;
	for (auto &seg : p) R.push_back(seg.r);
	vector <int> dp(k + 1);
	for (int i = 0; i < k; i++) {
		int pos = lower_bound(R.begin(), R.end(), p[i].l) - R.begin();
		dp[i + 1] = max(dp[i], dp[pos] + p[i].r - p[i].l + 1);
	}
	cout << dp[k] << '\n';
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