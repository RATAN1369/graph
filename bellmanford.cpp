#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

ll n, m;
vector<ll> dis;
vector<tuple<ll, ll, ll>> edges;

bool bellman_ford(ll src) {
    dis.assign(n, 1e18);
    dis[src] = 0;

    for (ll i = 0; i < n - 1; i++) {
        for (auto [u, v, w] : edges) {
            if (dis[u] < 1e18 && dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
            }
        }
    }

    // Check for negative cycle
    for (auto [u, v, w] : edges) {
        if (dis[u] < 1e18 && dis[v] > dis[u] + w) {
            return false; // Negative cycle detected
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    for (ll i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        edges.pb({a, b, c});
    }

    if (!bellman_ford(0)) {
        cout << "there is a negative cycle" << endl;
    } else {
        for (ll d : dis) {
            cout << d << " ";
        }
        cout << endl;
    }
}
