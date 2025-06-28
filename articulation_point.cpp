#include<bits/stdc++.h>
#define int long long
#define vi vector<int>
#define endl '\n'
using namespace std;
 
int n,m;
int timer;
int totalCompo;
vector<vi>g;
vi extras; // stores the extras of 
vi tin,low;
vi vis;
vi AP;
vi subtree;
vi parent;
vi prod;


void subtreefinder(int node,int par){
    
    vis[node]=1;
    parent[node]=par; 
    int st=1;
    for(auto v:g[node]){
        if(!vis[v]){
            subtreefinder(v,node);
            st+=subtree[v];
        }
    }
    subtree[node]=st;
}


void dfs(int node,int par){
    vis[node]=1;
    tin[node]=low[node]=timer++;
    int child=0;
    vi childnodes;
    for(auto v:g[node]){
        if(v==par) continue;
        if(vis[v]){
            low[node]=min(low[node],tin[v]); // backedge
        }else{
            childnodes.push_back(v); // store unvisited childen so that they occur only once in the array
            dfs(v,node);
            low[node]=min(low[node],low[v]); // foreward edges hai
            if(low[v]>=tin[node] && par!=0){ //  AP condition
                if(AP.empty() || AP.back()!=node)
                    AP.push_back(node);
            }
            child++;
        }
    }
    if(par==0){
        extras[node]=child;
    }else{
        for(auto ch:childnodes){
            if(low[ch]>=tin[node]){ 
                // the childern that satisfy the AP condition will increase the # components
                extras[node]++;
            }
        }
    }
    if(par==0 && child>1){
        AP.push_back(node);
    }
}


void solve(){
    cin>>n>>m;
    g.resize(n+1);
    vis.assign(n+1,0);
    tin.assign(n+1,0);
    low.assign(n+1,0);
    parent.assign(n+1,0);
    prod.assign(n+1,n-1);
    extras.assign(n+1,1);
    subtree.assign(n+1,0);
    
    timer=0;
    totalCompo=0;


    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }


    // find subtrees
    subtreefinder(1,0);
    //! dont forget to reassign vis array
    vis.assign(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            totalCompo++;
            dfs(i,0);
        }
    }
    // getting the prod arr that stores the product of subtrees after removing current element
    for(auto nn:AP){
        int p=1;
        if(nn!=1){
            p=p*(subtree[1]-subtree[nn]);
        }
        for(auto v:g[nn]){
            if(v!=parent[nn]){
                p=p*subtree[v];
            }
        }
        prod[nn]=p;
    }
    cout<<"APs " <<endl;
    for(int i=0;i<AP.size();i++){
        cout<<AP[i]<<" ";
    }
    cout<<endl;
    cout<<"subtrees " <<endl;
    for(int i=1;i<=n;i++){
        cout<<subtree[i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"Extras: "<<endl;
    for(int i=1;i<=n;i++){
        cout<<extras[i]<<" ";
    }
    cout<<endl;
    cout<<"Product of components "<<endl;
    for(int i=1;i<=n;i++){
        cout<<prod[i]<<" ";
    }
    cout<<endl;


}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // int t;cin>>t;while(t-->0)
    solve();
    return 0;
}