#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, m;
	cin >> n >> m ;
	vector <int> a(n + 1);
	int lst = -1, cnt = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){
		if(a[i] != lst) {
			cnt = 0;
		}
		lst = a[i];
		cnt++;
		if (cnt == m){
			cout << "NO" <<'\n';
			return;
		}
	}
	cout << "YES" << '\n';

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
