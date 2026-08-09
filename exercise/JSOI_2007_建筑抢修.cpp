#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct City{
	int t1, t2;
	bool operator < (const City &others) const {
		return t2 != others.t2 ? t2 < others.t2 : t1 < others.t1;
	}
};

void solve() {
	int n;
	cin >> n;
	vector <City> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].t1 >> a[i].t2;
	}
	sort(a.begin(), a.end());
	priority_queue <int> q;
	int cur = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt++;
		cur += a[i].t1;
		q.push(a[i].t1);
		if (cur > a[i].t2) {
			cnt--;
			cur -= q.top();
			q.pop();
		}
	}
	cout << cnt << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int T = 1;
	// cin >> T;
	while(T--) {
	    solve();
	}
	return 0; 
}