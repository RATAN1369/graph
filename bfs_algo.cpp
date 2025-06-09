#include<bits/stdc++.h>
using namespace std;
#define ll long long 
using state = pair<ll,ll>;
#define F first
#define S second
#define mp make_pair
ll n, m;
vector<vector<ll>> dis;
vector<vector<char>> v;
vector<vector<pair<ll,ll>>> par;

ll dx[] = {-1, 1, 0, 0};
ll dy[] = {0, 0, -1, 1};

bool is_valid(ll x, ll y){
    return (x >= 0 && x < n && y >= 0 && y < m && v[x][y] != '#');
}

vector<state> neighbours(state node){
    vector<state> vec;
    for(int i = 0; i < 4; i++){
        ll x = node.F + dx[i];
        ll y = node.S + dy[i];
        if(is_valid(x, y)){
            vec.push_back({x, y});
        }
    }
    return vec;
}

void bfs(state st){
    queue<state> q;
    q.push(st);
    dis[st.F][st.S] = 0;
    par[st.F][st.S] = {-1,-1};
    while(!q.empty()){
        state node = q.front();
        q.pop();
        for(state x : neighbours(node)){
            if(dis[x.F][x.S] == 1e9){
                dis[x.F][x.S] = dis[node.F][node.S] + 1;
                par[x.F][x.S] = {node.F,node.S};
                q.push(x);
            }
        }
    }
}

int main(){
    cin >> n >> m;
    dis.resize(n, vector<ll>(m, 1e9));
    v.resize(n, vector<char>(m));
    par.resize(n, vector<pair<ll,ll>>(m, {-1,-1}));

    state st, en;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            cin >> v[i][j];
            if(v[i][j] == 'S') st = {i, j};
            if(v[i][j] == 'F') en = {i, j};
        }
    }

    bfs(st); 

    if(dis[en.F][en.S] == 1e9){
        cout << "path is not Reachable" << endl;
    } else {
            vector<state> ans;
            state cur = en;
            while (cur != mp(-1LL, -1LL)) {
                ans.push_back(cur);
                cur = par[cur.F][cur.S];
            }
            reverse(ans.begin(), ans.end());
            for (auto p : ans) {
                cout << "(" << p.F << "," << p.S << ") ";
            }
            cout << endl;

    }
}
