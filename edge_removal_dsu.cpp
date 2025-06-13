#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int n, set_size;
int *parent, *rank_;

void init(int a) {
    n = set_size = a;
    parent = new int[n + 1];
    rank_ = new int[n + 1];
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rank_[i] = 1;
    }
}

int find(int x) {
    if (x != parent[x]) parent[x] = find(parent[x]);
    return parent[x];
}

void merge(int x, int y) {
    int xcur = find(x), ycur = find(y);
    if (xcur == ycur) return;
    if (rank_[xcur] >= rank_[ycur]) {
        parent[ycur] = xcur;
        rank_[xcur] += rank_[ycur];
    } else {
        parent[xcur] = ycur;
        rank_[ycur] += rank_[xcur];
    }
    set_size--;
}

int main() {
    ll m, q;
    cin >> n >> m >> q;
    init(n);

    vector<pair<ll, ll>> edges(m + 1); // 1-based index for ease
    for (ll i = 1; i <= m; i++) {
        ll u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }

    set<ll> deleted;
    vector<pair<ll, ll>> ops;

    for (ll i = 0; i < q; i++) {
        ll type;
        cin >> type;
        if (type == 1) {
            ll id;
            cin >> id;
            ops.push_back({1, id});
            deleted.insert(id);
        } else {
            ops.push_back({2, -1});
        }
    }

    for (ll i = 1; i <= m; i++) {
        if (deleted.find(i) == deleted.end()) {
            merge(edges[i].first, edges[i].second);
        }
    }

    vector<ll> res;
    for (ll i = ops.size() - 1; i >= 0; i--) {
        if (ops[i].first == 2) {
            res.push_back(set_size);
        } else {
            ll id = ops[i].second;
            merge(edges[id].first, edges[id].second);
        }
    }

    reverse(res.begin(), res.end());
    for (ll x : res) cout << x << "\n";

    return 0;
}
