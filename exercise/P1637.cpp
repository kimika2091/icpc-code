#include<bits/stdc++.h>
using namespace std;
using ll = long long;

template <class T>
struct BIT {
    int n;
    vector<T> c;
    BIT(int n) : n(n), c(n + 1, 0) {}
    void add(int x, const T &v) {
        for (; x <= n; x += x & -x)
            c[x] = c[x] + v;
    }
    T sum(int x) {
        T ans{};
        for (; x > 0; x -= x & -x)
            ans = ans + c[x];
        return ans;
    }
    T sum(int x, int y) {
        return sum(y) - sum(x - 1);
    }
};
const int N = 1e5;

void solve() {
	int n;
	cin >> n;
	vector<int> f(N + 1, 0);
	vector<BIT<int>> tr(2, BIT<int>(N + 1));
	ll ans = 0;
	for (int i = 1, x; i <= n; i++) {
		cin >> x;
		tr[0].add(x, 1);
		int sum1 = tr[0].sum(x - 1);
		if (sum1) {
			tr[1].add(x, sum1);
			ans += tr[1].sum(x - 1);
		}
	}
	cout << ans << '\n';
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
