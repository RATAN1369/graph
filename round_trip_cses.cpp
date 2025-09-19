#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define yes cout<<"YES"<<"\n"
#define no cout<<"NO"<<"\n"
#define one cout<<-1<<"\n"
#define M 1000000007
#define pb push_back

ll n,m;
vector<ll> adj[200100];
vector<ll> vis;
vector<ll> back;
vector<ll> ans;
bool is_bi=false;

void dfs(ll node,ll par){
    if(is_bi) return;
    vis[node]=1;
    for(auto v: adj[node]){
        if(is_bi) return;
        if(!vis[v]){
            back[v]=node;
            dfs(v,node);
        }else if(v!=par){
            is_bi=true;
            ll cur=node;
            while(cur!=v){
                ans.push_back(cur);
                cur=back[cur];
            }
            ans.push_back(v);
            ans.push_back(node); // close the cycle
            return;
        }
    }
}

void solve() {
    cin>>n>>m;
    for(ll i=0; i<m; i++){
        ll u,v; cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vis.assign(n+1,0);
    back.assign(n+1,0);
    for(ll i=1; i<=n; i++){
        if(!vis[i]){
            dfs(i,-1);
        }
    }
    if(!is_bi){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    cout<<ans.size()<<"\n";  // length of cycle
    for(auto it: ans){
        cout<<it<<" ";
    }
    cout<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    solve();        
    return 0;
}
