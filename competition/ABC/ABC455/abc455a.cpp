#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int a,b,c;
	cin>>a>>b>>c;
	if (a!=b && b==c) cout<<"Yes";
	else cout<<"No";
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
