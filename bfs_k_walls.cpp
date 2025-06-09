#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define F first
#define S second
vector<vector<char>> v;
vector<vector<vector<ll>>> dis;
ll n,m,k;
ll dx[]={1,-1,0,0};
ll dy[]={0,0,1,-1};

bool is_valid(ll x, ll y){
    return x>=0 && x<n && y>=0 && y<m;
    
}
vector<pair<ll,ll>> neighbours(ll x, ll y ){
     vector<pair<ll,ll>> vec;
     for(ll i=0; i<4; i++){
        pair<ll,ll> node;
        ll nx=x+dx[i];
        ll ny=y+dy[i];
        if(is_valid(nx,ny)){
            node={nx,ny};
            vec.push_back(node);
        }
     }
     return vec;
}

void bfs(pair<pair<ll,ll>,ll> st){
    ll x=st.F.F;
    ll y=st.F.S;
    ll z=st.S;
    dis[x][y][z]=0;
    queue<pair<pair<ll,ll>,ll>> q;
    q.push(st);
    while(!q.empty()){
        ll x=q.front().F.F;
        ll y=q.front().F.S;
        ll z=q.front().S;
        q.pop();
        for(auto u: neighbours(x,y)){
            ll nx=u.F;
            ll ny=u.S;
            ll nz = z + (v[nx][ny] == '#' ? 1 : 0);
            if(nz <= k && dis[nx][ny][nz] == 1e9){
                dis[nx][ny][nz] = dis[x][y][z] + 1;
                q.push({{nx, ny}, nz});
            }
        }
    }
}

int main(){
    cin>>n>>m>>k;
    v.resize(n,vector<char>(m));
    dis.resize(n,vector<vector<ll>>(m,vector<ll>(k+1,1e9)));
    pair<ll,ll> st,en;
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            cin>>v[i][j];
            if(v[i][j]=='S'){
                st={i,j};
            }
            if(v[i][j]=='E'){
                en={i,j};
            }
        }
    }
    bfs({st,0});
    ll ans=1e9;
    for(ll i=0; i<=k; i++){
        ans=min(ans,dis[en.F][en.S][i]);
    }
    cout<< (ans==1e9 ? -1 : ans) << endl;
}
/*
6 6 0
S . # . . .
. . # . . .
# . # . # .
. . . . # .
# # # # . .
E . . . . .

*/