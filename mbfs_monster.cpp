#include<bits/stdc++.h>
using namespace std;
#define ll long long 
using state = pair<ll,ll>;
#define F first
#define S second

ll n, m;
vector<vector<ll>> dis;
vector<vector<char>> v;
vector<vector<ll>> mon_dis;
vector<pair<ll,ll>> mon;
vector<vector<char>> par;

ll dx[] = {-1, 1, 0, 0};
ll dy[] = {0, 0, -1, 1};
char dir[4] = {'U', 'D', 'L', 'R'};

bool is_valid(ll x, ll y) {
    return (x >= 0 && x < n && y >= 0 && y < m && v[x][y] != '#');
}

void bfs(state st) {
    queue<state> q;
    q.push(st);
    dis[st.F][st.S] = 0;
    par[st.F][st.S] = ' ';  // Starting point has no parent

    while(!q.empty()) {
        state node = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            ll x = node.F + dx[i];
            ll y = node.S + dy[i];
            if(is_valid(x, y) && dis[x][y] == 1e9) {
                dis[x][y] = dis[node.F][node.S] + 1;
                par[x][y] = dir[i];  // Store the direction taken to reach (x,y)
                q.push({x, y});
            }
        }
    }
}

void mon_bfs(vector<state> monsters) {
    queue<state> q;
    for(auto it: monsters) {
        q.push(it);
        mon_dis[it.F][it.S] = 0;
    }

    while(!q.empty()) {
        state node = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            ll x = node.F + dx[i];
            ll y = node.S + dy[i];
            if(is_valid(x, y) && mon_dis[x][y] == 1e9) {
                mon_dis[x][y] = mon_dis[node.F][node.S] + 1;
                q.push({x, y});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    dis.assign(n, vector<ll>(m, 1e9));
    mon_dis.assign(n, vector<ll>(m, 1e9));
    v.assign(n, vector<char>(m));
    par.assign(n, vector<char>(m));

    state st, en;
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            cin >> v[i][j];
            if(v[i][j] == 'A') st = {i, j};
            if(v[i][j] == 'M') mon.push_back({i, j});
        }
    }

    bfs(st);
    mon_bfs(mon);

    ll ans = 1e10;
    // Check all exit points on the boundaries where A can escape before monsters arrive
    for(ll i = 0; i < n; i++) {
        // Right boundary
        if(v[i][m-1] != '#' && dis[i][m-1] < mon_dis[i][m-1] && dis[i][m-1] < ans) {
            ans = dis[i][m-1];
            en = {i, m-1};
        }
        // Left boundary
        if(v[i][0] != '#' && dis[i][0] < mon_dis[i][0] && dis[i][0] < ans) {
            ans = dis[i][0];
            en = {i, 0};
        }
    }
    for(ll j = 0; j < m; j++) {
        // Bottom boundary
        if(v[n-1][j] != '#' && dis[n-1][j] < mon_dis[n-1][j] && dis[n-1][j] < ans) {
            ans = dis[n-1][j];
            en = {n-1, j};
        }
        // Top boundary
        if(v[0][j] != '#' && dis[0][j] < mon_dis[0][j] && dis[0][j] < ans) {
            ans = dis[0][j];
            en = {0, j};
        }
    }

    if(ans == 1e10) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        cout << ans << "\n";

        string path;
        state cur = en;

        // Reconstruct the path by moving backward from exit to start
        while(cur != st) {
            char d = par[cur.F][cur.S];
            path.push_back(d);
            if(d == 'U') cur = {cur.F + 1, cur.S};
            else if(d == 'D') cur = {cur.F - 1, cur.S};
            else if(d == 'L') cur = {cur.F, cur.S + 1};
            else if(d == 'R') cur = {cur.F, cur.S - 1};
        }

        reverse(path.begin(), path.end());
        cout << path << "\n";
    }

    return 0;
}
