#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define F first 
#define S second
#define MP make_pair

vector<vector<char>> v;
vector<vector<ll>> dis;
ll n,m;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
char dir[4]={'U','D','L','R'};

void bfs(ll x, ll y) {
    dis[x][y] = 0;
    deque<pair<ll, pair<ll, ll>>> q;
    q.push_front(MP(0, MP(x, y)));

    while (!q.empty()) {
        auto ele = q.front(); q.pop_front();
        ll cost = ele.F;
        ll xx = ele.S.F;
        ll yy = ele.S.S;

        for (ll i = 0; i < 4; i++) {
            ll nx = xx + dx[i];
            ll ny = yy + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                ll new_cost = cost + (v[xx][yy] != dir[i]);
                if (dis[nx][ny] > new_cost) {
                    dis[nx][ny] = new_cost;
                    if (v[xx][yy] == dir[i])
                        q.push_front(MP(new_cost, MP(nx, ny)));
                    else
                        q.push_back(MP(new_cost, MP(nx, ny)));
                }
            }
        }
    }
}


int main(){
cin>>n>>m;
v.resize(n,vector<char>(m));
dis.resize(n,vector<ll>(m,1e18));
for(ll i=0; i<n; i++){
    for(ll j=0; j<m; j++){
        cin>>v[i][j];
    }
}
bfs(0,0);
cout<<dis[n-1][m-1]<<endl;



}