#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define F first
#define S second
#define pb push_back
#define MP make_pair

using state = pair<ll,ll>; 

ll n, m;
vector<ll> dis;
vector<ll> vis;
vector<vector<state>> adj; 

void dijkstra(state st){
    priority_queue<state> q;
    dis[st.S] = 0;
    q.push({-0, st.S});
    while (!q.empty()) {
        state node = q.top(); q.pop();
        if (vis[node.S]) continue;
        vis[node.S] = 1;
        ll cur_dist=-(node.F);
        for (auto it : adj[node.S]) {
            ll v = it.F, wt = it.S;
            if (dis[v] > cur_dist + wt) {
                dis[v] = cur_dist + wt;
                q.push(MP(-dis[v], v));
            }
        }
    }
}

int main(){
    cin >> n >> m;
    dis.assign(n+1, 1e18);
    vis.assign(n+1, 0);
    adj.resize(n+1);
    vector<pair<pair<ll,ll>,ll>> x;
    for (ll i = 0; i < m; i++) {
        ll a, b, c; cin >> a >> b >> c;
        adj[a].pb(MP(b, c));
        adj[b].pb(MP(a, c)); 
        x.pb(MP(MP(a,b),c));
        //  x.pb(MP(MP(b,a),c));
    }
    ll node; cin>>node;// node at whixh we are setting fire 
    dijkstra(MP(0, node));
    ll ans=-1e18;
    for(ll i=1; i<=n; i++){
            ans=max(ans,(ll)dis[i]*10);
    }
    for(auto it: x){
        ll from=it.F.F;
        ll to=it.F.S;
        ll distance=it.S;
        if(abs(dis[from]-dis[to])>=distance){
            ans=max(ans,(ll)(min(dis[from],dis[to])+distance)*(ll)10);
        }else{
            ans=max(ans,(ll)((dis[from]+dis[to]+distance)*5));
        }
    }
    cout<<ans<<endl;
    
}