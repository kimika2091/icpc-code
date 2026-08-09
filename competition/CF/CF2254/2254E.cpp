#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    multiset<ll> rem;
    ll total = 0;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        total += x;
        rem.insert(x);
    }
    if (total <= 0) {
        cout << -1 << '\n';
        return;
    }
    vector<ll> answer;
    ll prefix = 0;
    while (!rem.empty()) {
        auto it = rem.upper_bound(-prefix);
        if (it == rem.end()) {
            cout << -1 << '\n';
            return;
        }
        prefix += *it;
        answer.push_back(prefix);
        rem.erase(it);
    }
    for (int i = 0; i < n; ++i) {
        cout << answer[i] << (i + 1 == n ? '\n' : ' ');
    }
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