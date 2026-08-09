#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long

const int N = 500000;

struct BIT {
	int n;
    vector<int> c;
	BIT(int n) : n(n), c(n + 5, 0) {}
    void add(int x, const int &v) {
        for (; x <= n; x += x & -x)
            c[x] = c[x] + v;
    }
    int kth(int k) {
		int cur_sum = 0, pos = 0;
		for (int i = (1 << 18); i; i >>= 1) {
			if (pos + i <= n && cur_sum + c[pos + i] < k) {
				cur_sum += c[pos + i];
				pos += i;
			}
		} 
		return pos + 1;
	}
};

struct query{
	int id;
	ll x;
};

void solve() {
	int n, m;
	cin >> n >> m;
	vector <int> a(n + 1);
	vector <int> cnt(m + 1);
	vector <pair<int,int>> b;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	for (int i = 1; i <= m; i++) {
		b.push_back({cnt[i], i});
	}
	sort(b.begin(), b.end());
	int q;
	cin >> q;
	vector <query> Q;
	vector <int> ans(q + 1);
	for (int i = 1; i <= q; i++) {
		ll x;
		cin >> x;
		Q.push_back({i, x});
	}
	sort(Q.begin(), Q.end(), [&](query x, query y){ return x.x < y.x; });
	int cur = 0, len = n;
	BIT tr(N);
	tr.add(b[0].second, 1);
	for (auto [id, x] : Q) {
		while (cur < m - 1 && len < x) {
			while (cur < m - 1 && b[cur].first == b[cur + 1].first) {
				cur ++;
				tr.add(b[cur].second, 1);
			}
			if (cur < m - 1 && len < x) {
				len += cur + 1;
				b[cur].first ++;
			}
		}
		if (x <= n) {
			ans[id] = a[x];
			continue;
		}	
		if (cur == m - 1) {
			int p = (x - len) % m;
			if (p == 0) p = m;
			ans[id] = p;
		}
		else {
			int p = tr.kth(x - len + cur + 1);
			ans[id] = p;
		}
	}
	for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
}

signed main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	int T = 1;
	// cin >> T;
	while(T--) {
		solve();
	}
	return 0; 
}


// M = 30

// 20 26 3 14 4 4 9 
// 20 26 3 14 4 4 9 1
// 20 26 3 14 4 4 9 1 2 
// 20 26 3 14 4 4 9 1 2 5
// 20 26 3 14 4 4 9 1 2 5 6 ...... || 1 ~ M 1 ~ M