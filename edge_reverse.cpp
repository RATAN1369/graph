#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define MP make_pair

vector<vector<ll>> adj;
vector<vector<ll>> can;
vector<ll> dis;
ll n, m;

void bfs(ll node) {
    dis[node] = 0;
    deque<pair<ll, ll>> q;
    q.push_back(MP(0, node));
    while (!q.empty()) {
        auto it = q.front();
        q.pop_front();
        ll dist = it.F;
        ll node = it.S;
        for (auto nod : adj[node]) {
            if (dis[nod] > dist) { // dont do dis[nod]==1e18
                dis[nod] = dist;
                q.push_front(MP(dis[nod], nod));
            }
        }
        for (auto nod : can[node]) {
            if (dis[nod] > dist + 1) {
                dis[nod] = dist + 1;
                q.push_back(MP(dis[nod], nod));
            }
        }
    }
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        cin >> n >> m;
        adj.assign(n + 1, {});
        can.assign(n + 1, {});
        dis.assign(n + 1, 1e18);

        for (ll j = 0; j < m; j++) {
            ll a, b;
            cin >> a >> b;
            if (a == b) continue; // skip self-loops
            adj[a].push_back(b);  // original direction (cost 0)
            can[b].push_back(a);  // reversed direction (cost 1)
        }

        bfs(1);
        if (dis[n] == 1e18)
            cout << -1 << endl;
        else
            cout << dis[n] << endl;
    }
}