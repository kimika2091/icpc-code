#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int B_SIZE = 548;

int tot = 1;
vector <vector<int>> blocks(B_SIZE + 1);

auto find(int k) {
	int p = 1;
	while(k > blocks[p].size()) {
		k -= blocks[p].size();
		p++;
	}
	return make_pair(p, k - 1);
}

void rebuild(int p) {
	vector <int> stk;
	for (int i = p; i <= tot; i++) {
		for (int j : blocks[i]) stk.push_back(j);
		blocks[i].clear();
	}
	tot = p;
	for (int i : stk) {
		blocks[tot].push_back(i);
		if (blocks[tot].size() == B_SIZE) tot++;
	}
}

void insert(int k, int x) {
	auto [p, t] = find(k);
	blocks[p].insert(blocks[p].begin() + t, x);
	if(blocks[p].size() > 2 * B_SIZE) rebuild(p);
}

int query(int k) {
	auto [p, t] = find(k);
	return blocks[p][t];
}

void solve() {
	int n;
	cin >> n;
	for (int i = 1, x; i <= n; i++) {
		cin >> x;
		blocks[tot].push_back(x);
		if (blocks[tot].size() == B_SIZE) tot++;
	}
	for (int i = 1; i <= n; i++) {
		int opt;
		cin >> opt;
		if (opt == 0) {
			int l, r;
			cin >> l >> r;
			insert(l, r);
		}
		else {
			int c;
			cin >> c;
			cout << query(c) << '\n';
		}
	}
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