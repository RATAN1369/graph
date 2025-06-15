#include <bits/stdc++.h>
using namespace std;
#define ll long long 

vector<vector<char>> v;
ll n, k;
ll m=10;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(ll x, ll y, ll &com, char val, vector<pair<ll,ll>> &idx, vector<vector<ll>> &vis) {
    vis[x][y] = 1;
    idx.push_back({x, y});
    for (ll i = 0; i < 4; i++) {
        ll nx = x + dx[i];
        ll ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny] && v[nx][ny] == val) {
            com++;
            dfs(nx, ny, com, val, idx, vis);
        }
    }
}

int main() {
    cin >> n >> k;
    
    v.resize(n, vector<char>(m));
    for (ll i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (ll j = 0; j < m; j++) {
            v[i][j] = s[j];
        }
    }

    bool changed = true;
    while (changed) {
        changed = false;
        vector<vector<ll>> vis(n, vector<ll>(m, 0));

        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                if (!vis[i][j] && v[i][j] != '0') {
                    vector<pair<ll,ll>> idx;
                    ll com = 1;
                    dfs(i, j, com, v[i][j], idx, vis);
                    if (com >= k) {
                        changed = true;
                        for (auto p : idx) {
                            v[p.first][p.second] = '0';
                        }
                    }
                }
            }
        }

        // gravity step  //MPST IMP STEP LOL
        for (ll j = 0; j < m; j++) {
            ll write_row = n - 1;
            for (ll i = n - 1; i >= 0; i--) {
                if (v[i][j] != '0') {
                    v[write_row][j] = v[i][j];
                    if (write_row != i) v[i][j] = '0';
                    write_row--;
                }
            }
        }
    }

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cout << v[i][j];
        }
        cout << endl;
    }
}
