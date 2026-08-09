#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	string s;
	cin >> s;
	int n = s.size();
	vector <int> cnt(26);
	for (char c : s) {
		cnt[c - 'a']++;
	}
	int mx = 0;
	char ch;
	for (int i = 0; i < 26; i++) {
		if (cnt[i] > mx) {
			mx = cnt[i];
			ch = 'a' + i;
		}
	}
	bool ok = mx <= (n + 1) / 2;
	cout << (ok ? "Yes" : "No") << '\n';
	if (ok) {
		priority_queue <pair<int, int>> pq;
		for (int i = 0; i < 26; i++) {
			if (cnt[i]) pq.push({cnt[i], i});
		}
		string res = "";
		int lst = -1;
		while (!pq.empty()) {
			auto [w, c] = pq.top();
			pq.pop();
			if (lst != c) {
				res += ('a' + c);
				w--;
				lst = c;
				if (w) pq.push({w, c});
			}
			else {
				auto [w2, c2] = pq.top();
				pq.pop();
				res += ('a' + c2);
				w2--;
				lst = c2;
				if (w2) pq.push({w2, c2});
				pq.push({w, c});
			}
		}
		cout << res << '\n';
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