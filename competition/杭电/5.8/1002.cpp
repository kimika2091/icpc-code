#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector <vector<int>> a(n + 1, vector<int>(n + 1));
    set <int> s;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            s.insert(a[i][j]);
        }
    }
    auto check_h = [&](int x) -> bool {
        for (int i = 1; i <= n; i++) {
            bool f = 0;
            for (int j = 1; j <= n; j++) {
                if (a[i][j] == x) {
                    f = 1;
                    break;
                }
            }
            if (f == 0) return false;
        }
        return true;
    };
    auto check_w = [&](int x) -> bool {
        for (int j = 1; j <= n; j++) {
            bool f = 0;
            for (int i = 1; i <= n; i++) {
                if (a[i][j] == x) {
                    f = 1;
                    break;
                }
            }
            if (f == 0) return false;
        }
        return true;
    };
    vector <int> ans;
    for (int num : s) {
        if (check_h(num) && check_w(num)) ans.push_back(num);
    }
    cout << ans.size() << '\n';
    for (int i : ans) cout << i << ' ';
    cout << '\n';
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
