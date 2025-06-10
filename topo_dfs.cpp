#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define F first
#define S second
#define pb push_back
#define MP make_pair

using state = pair<ll,ll>; 

ll n, m;
vector<ll> topo;
vector<ll> vis;
vector<vector<ll>> adj;


void dfs(ll node){
    vis[node]=1;
    for(auto it: adj[node]){
       if(!vis[it]) dfs(it);
    }
    topo.pb(node);
}


int main(){
    cin >> n >> m;
    vis.assign(n+1, 0);
    adj.resize(n+1);
    for (ll i = 0; i < m; i++) {
         ll a,b; cin>>a>>b;
         adj[a].pb(b); 
    }
    for(ll i=1; i<=n; i++) if(!vis[i]) dfs(i);
    reverse(topo.begin(), topo.end());

    for(auto it: topo) {
        cout<<it<<" ";
    }
    cout<<endl;
  
    
}