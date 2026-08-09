#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) {
        x = 1; y = 0;
        return;
    }
    exgcd(b, a % b, y, x);
    y -= a / b * x;
}

void solve() {
	int x;
	cin >> x;
	auto check = [&](int n) -> bool {
		for (int i = 0; i < 11; i++) {
			if (111 * i > n) break;
			if ((n - 111 * i) % 11 == 0) return true;
		}
		return false;
	};
	cout << (check(x)? "YES" : "NO") << '\n';
}

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	int T = 1;
	cin >> T;
	while(T--) {
		solve();
	}
	return 0; 
}
