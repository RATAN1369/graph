#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define F find
#define S second

vector<vector<ll>> dis;
ll n, m, q;

void floyd() {
    for (ll k = 1; k <= n; k++) {
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= n; j++) {
                if (dis[i][k] < 1e18 && dis[k][j] < 1e18) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
    }
}

int main() {
    cin >> n >> m >> q;
    dis.resize(n + 1, vector<ll>(n + 1, 1e18));

    for (ll i = 0; i < m; i++) {
        ll u, v, d;
        cin >> u >> v >> d;
        dis[u][v] = min(dis[u][v], d);
         dis[v][u] = min(dis[v][u], d);//roads are birectianal 
    }

    for (ll i = 1; i <= n; i++) {
        dis[i][i] = 0;
    }

    floyd();

    while (q--) {
        ll x, y;
        cin >> x >> y;
        if (dis[x][y] == 1e18) {
            cout << -1 << endl;
        } else {
            cout << dis[x][y] << endl;
        }
    }
}
