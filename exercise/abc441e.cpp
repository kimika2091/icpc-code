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

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector <int> a(n + 1), b(n + 1), c(n + 1);
	for (int i = 0; i < n; i++) {
		a[i + 1] = a[i], b[i + 1] = b[i];
		switch(s[i]) {
			case 'A' : a[i + 1] ++; break;
			case 'B' : b[i + 1] ++; break;
		}
		c[i + 1] = a[i + 1] - b[i + 1] + n + 1;
	}
	BIT<int> tr(2 * n + 5);
	tr.add(n + 1, 1);
	ll ans = 0;
	for (int r = 1; r <= n; r++) {
		ans += tr.sum(c[r] - 1);
		tr.add(c[r], 1);
	}
	cout << ans << endl;
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
