#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    cout << 2 * n << '\n';
    vector <pair<double, double>> a;
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            a.emplace_back(i * 0.011, j * 0.011);
        }
    }
    for (int i = 0; i < n; i++) cout << a[i].first << ' ' << a[i].second << ' ' << 0 << '\n';
    for (int i = 0; i < n; i++) cout << a[i].first << ' ' << a[i].second << ' ' << 1 << '\n';
}

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	int T = 1;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0; 
}