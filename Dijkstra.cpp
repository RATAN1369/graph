#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define F first
#define S second
#define pb push_back

using state = pair<ll,ll>; 

ll n, m;
vector<ll> dis;
vector<ll> vis;
vector<vector<state>> adj; 

void dijkstra(state st){
    priority_queue<state> q;
    dis[st.S] = 0;
    q.push({0, st.S});
    while (!q.empty()) {
        state node = q.top(); q.pop();
        if (vis[node.S]) continue;
        vis[node.S] = 1;
        for (auto it : adj[node.S]) {
            ll v = it.F, wt = it.S;
            if (dis[v] > dis[node.S] + wt) {
                dis[v] = dis[node.S] + wt;
                q.push({-dis[v], v});
            }
        }
    }
}

int main(){
    cin >> n >> m;
    dis.assign(n, 1e18);
    vis.assign(n, 0);
    adj.resize(n);
    for (ll i = 0; i < m; i++) {
        ll a, b, c; cin >> a >> b >> c;
        adj[a].pb({b, c});
        adj[b].pb({a, c}); 
    }

    dijkstra({0, 0});
    for (auto it : dis) cout << it << " ";
    cout << endl;
}
