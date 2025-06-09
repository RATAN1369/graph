#include<bits/stdc++.h>
using namespace std;
#define ll long long 
using state = pair<ll,ll>;
#define F first
#define S second

ll n, m;
vector<vector<ll>> inf_dis;
vector<vector<ll>> grid;
vector<pair<ll,ll>> inf;

ll dx[] = {-1, 1, 0, 0};
ll dy[] = {0, 0, -1, 1};

bool is_valid(ll x, ll y) {
    return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != 0);
}

void inf_bfs(vector<state> monsters) {
    queue<state> q;
    for(auto it: monsters) {
        q.push(it);
        inf_dis[it.F][it.S] = 0;
    }

    while(!q.empty()) {
        state node = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            ll x = node.F + dx[i];
            ll y = node.S + dy[i];
            if(is_valid(x, y) && inf_dis[x][y] == 1e9) {
                inf_dis[x][y] = inf_dis[node.F][node.S] + 1;
                q.push({x, y});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    grid.assign(n, vector<ll>(m));
    inf_dis.assign(n, vector<ll>(m, 1e9));

    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 2) inf.push_back({i, j});
        }
    }

    inf_bfs(inf);

    ll ans = 0;
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            if(grid[i][j] == 1) {
                if(inf_dis[i][j] == 1e9) {
                    cout << "-1\n";
                    return 0;
                }
                ans = max(ans, inf_dis[i][j]);
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
