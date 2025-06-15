#include <bits/stdc++.h>
using namespace std;
#define ll long long
//back endge and cross edge wala logic us for directed graph 
vector<vector<ll>> v;
vector<ll> vis, parents, cycle;
ll start = -1, end_node = -1;
bool is_cycle = false;

bool dfs(ll node) {
    vis[node] = 1;
    for (auto it : v[node]) {
        if (vis[it] == 0) {
            parents[it] = node;
            if (dfs(it)) return true;
        } else if (vis[it] == 1) {
            start = it;
            end_node = node;
            return true;
        }
    }
    vis[node] = 2;
    return false;
}

int main() {
    ll n, m;
    cin >> n >> m;
    v.assign(n + 1, {});
    vis.assign(n + 1, 0);
    parents.assign(n + 1, -1);

    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        v[a].push_back(b);  // directed edge
    }

    for (ll i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            if (dfs(i)) {
                is_cycle = true;
                break;
            }
        }
    }

    if (!is_cycle) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cycle.push_back(start);
        for (ll cur = end_node; cur != start; cur = parents[cur])
            cycle.push_back(cur);
        cycle.push_back(start);
        reverse(cycle.begin(), cycle.end());
        for (ll x : cycle)
            cout << x << " ";
        cout << endl;
    }
}
