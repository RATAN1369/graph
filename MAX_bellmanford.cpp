#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define MP make_pair
// time complexity : O(V*E)==O(V^3)
ll n, m;
vector<ll> dis;
vector<pair<pair<ll, ll>, ll>> edges;

bool bellman_ford(ll src) {
    dis.assign(n+1, -1e18);
    dis[src] = 0;

    for (ll i = 1; i <= n - 1; i++) {
        for (auto it : edges) {
            ll u=it.F.F;
            ll v=it.F.S;
            ll w=it.S;
            if (dis[u]!=-1e18 && dis[v] < dis[u] + w) {
                dis[v] = dis[u] + w;
            }
        }
    }

    // Check for negative cycle
    for (auto it : edges) {
            ll u=it.F.F;
            ll v=it.F.S;
            ll w=it.S;
        if (dis[u]!=-1e18 && dis[v] < dis[u] + w) {
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
        edges.pb(MP(MP(a, b),c));
    }

    if (!bellman_ford(1)) {
        cout << "-1" << endl;
    } else {
       cout<<dis[n]<<endl;
       
    }
}
