#include<bits/stdc++.h>
using namespace std;
using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct FHQ_Treap {
    struct Node {
        int l, r;      
        int val, key;  
        int size; 
    };

    vector<Node> tr;
    int root, cnt;

    FHQ_Treap(int n) {
        tr.resize(n + 1);
        root = cnt = 0;
    }

    int new_node(int v) {
        tr[++cnt] = {0, 0, v, (int)rng(), 1};
        return cnt;
    }

    void pushup(int p) {
        tr[p].size = tr[tr[p].l].size + tr[tr[p].r].size + 1;
    }

    // 按值 v 分裂成 x(<=v) 和 y(>v)
    void split(int p, int v, int &x, int &y) {
        if (!p) { x = y = 0; return; }
        if (tr[p].val <= v) {
            x = p;
            split(tr[p].r, v, tr[p].r, y);
        } else {
            y = p;
            split(tr[p].l, v, x, tr[p].l);
        }
        pushup(p); 
    }

    // 合并 x 和 y，返回新根
    int merge(int x, int y) {
        if (!x || !y) return x + y;
        if (tr[x].key < tr[y].key) {
            tr[x].r = merge(tr[x].r, y);
            pushup(x); return x;
        } else {
            tr[y].l = merge(x, tr[y].l);
            pushup(y); return y;
        }
    }

    // 1. 插入
    void insert(int v) {
        int x, y;
        split(root, v, x, y);
        root = merge(merge(x, new_node(v)), y);
    }

    // 2. 删除 (仅删除一个 v)
    void remove(int v) {
        int x, y, z;
        split(root, v, x, z);
        split(x, v - 1, x, y);
        if (y) y = merge(tr[y].l, tr[y].r); // 删掉 y 的根
        root = merge(merge(x, y), z);
    }

    // 3. 查询 v 的排名
    int get_rank(int v) {
        int x, y;
        split(root, v - 1, x, y);
        int res = tr[x ].size + 1;
        root = merge(x, y);
        return res;
    }

    // 4. 查询排名为 k 的值
    int get_by_rank(int k) {
        int p = root;
        while (p) {
            if (k <= tr[tr[p].l].size) p = tr[p].l;
            else if (k == tr[tr[p].l].size + 1) return tr[p].val;
            else {
                k -= tr[tr[p].l].size + 1;
                p = tr[p].r;
            }
        }
        return -1; // 未找到
    }

    // 5. 前驱
    int get_prev(int v) {
        int x, y;
        split(root, v - 1, x, y);
        int res = (x ? get_by_rank_in_subtree(x, tr[x].size) : -2147483647);
        root = merge(x, y);
        return res;
    }

    // 6. 后继
    int get_next(int v) {
        int x, y;
        split(root, v, x, y);
        int res = (y ? get_by_rank_in_subtree(y, 1) : 2147483647);
        root = merge(x, y);
        return res;
    }

private:
    // 内部辅助：在指定子树内查排名
    int get_by_rank_in_subtree(int p, int k) {
        while (p) {
            if (k <= tr[tr[p].l].size) p = tr[p].l;
            else if (k == tr[tr[p].l].size + 1) return tr[p].val;
            else { k -= tr[tr[p].l].size + 1; p = tr[p].r; }
        }
        return -1;
    }
};

void solve() {
	
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
