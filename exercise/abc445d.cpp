#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct Piece{
	int h, w;
};

struct Node{
	int id;
	int val;
	bool operator<(const Node& other) const {
		return val != other.val? val < other.val : id < other.id;
	}
};

void solve() {
	int h, w, n;
	cin >> h >> w >> n;
	vector <Piece> pieces(n + 1);
	set <Node> H, W;
	for (int i = 1; i <= n; i++) {
		cin >> pieces[i].h >> pieces[i].w;
		H.insert({i, pieces[i].h});
		W.insert({i, pieces[i].w});
	}
	int cur_h = h, cur_w = w, x = 1, y = 1;
	vector <pair<int, int>> ans(n + 1);
	while (true) {
		if (cur_h == 0 || cur_w == 0) break;
		int id = H.rbegin()->id;
		if (pieces[id].h == cur_h){
			// cout << "A:" << id << endl;
			cur_w -= pieces[id].w;
			ans[id] = {x, y};
			y += pieces[id].w;
			H.erase({id, pieces[id].h});
			W.erase({id, pieces[id].w});
		}
		else {
			id = W.rbegin()->id;
			// cout << "B:" << id << endl;
			cur_h -= pieces[id].h;
			ans[id] = {x, y};
			x += pieces[id].h;
			H.erase({id, pieces[id].h});
			W.erase({id, pieces[id].w});		
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i].first << ' ' << ans[i].second << endl;
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
