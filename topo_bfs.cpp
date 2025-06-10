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
vector<ll> indegree;

vector<vector<ll>> adj;


void bfs(){
     queue<ll> q;
    for (ll i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        ll node = q.front(); q.pop();
        topo.pb(node);

        for (auto it : adj[node]) {
            indegree[it]--;
            if (indegree[it] == 0) {
                q.push(it);
            }
        }
    }
}


int main(){
    cin >> n >> m;
    vis.assign(n+1, 0);
    adj.resize(n+1);
    indegree.assign(n+1, 0);
    for (ll i = 0; i < m; i++) {
         ll a,b; cin>>a>>b;
         adj[a].pb(b); 
         indegree[b]++;
    }
      bfs();
    

    for(auto it: topo) {
        cout<<it<<" ";
    }
    cout<<endl;
  
    
}