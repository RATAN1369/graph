#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
vector<vector<ll>> g;
vector<vector<ll>> grev;
vector<ll> tout;
ll n,m;
ll cur_scc=0;
vector<ll> scc;
vector<ll> vis;
void dfs1(ll node){
    vis[node]=1;
    for(auto it: g[node]){
        if(!vis[it]){
            dfs1(it);
        }
    }
    tout.pb(node);
}
void dfs2(ll node){
    vis[node]=1;
    scc[node]=(cur_scc);
    for(auto it: grev[node]){
        if(!vis[it]){
            dfs2(it);
        }
    }
}
vector<set<ll>> condence;

int main(){
    cin>>n>>m;
    g.resize(n+1);
    grev.resize(n+1);
    vis.resize(n+1,0);
    for(ll i=0; i<m; i++){
        ll a,b; cin>>a>>b;
        g[a].pb(b);
        grev[b].pb(a);
    }
    for(ll i=1; i<=n; i++){
        if(!vis[i]) dfs1(i);
    }
    scc.assign(n+1,0);
    vis.assign(n+1,0);
    
    reverse(tout.begin(),tout.end());
    for(auto i: tout){
         if(!vis[i]){
            cur_scc++;
            dfs2(i);
         }
    }
    cout<<cur_scc<<endl;
     condence.resize(cur_scc + 1);
    for(ll i=1; i<=n; i++){
        for(auto v: g[i]){
            if(scc[i]!=scc[v]){
                condence[scc[i]].insert(scc[v]);
            }
        }
    }


}


