#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define yes cout << "YES" << "\n"
#define no cout << "NO" << "\n"
#define one cout << -1 << "\n"
#define M 1000000007
#define pb push_back
 
long long int gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}
 
long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp = exp / 2;
    }
    return result;
}
 
ll fact(int n) {
    if (n == 0) return 1;
    else return (n * fact(n - 1)) % M;
}
 
vector<int> calculateZ(string s) {
    int n = s.length();
    vector<int> Z(n);
    int L = 0, R = 0;
    for (int i = 1; i < n; i++) {
        if (i > R) {
            L = R = i;
            while (R < n && s[R - L] == s[R]) R++;
            Z[i] = R - L; R--;
        } else {
            int k = i - L;
            if (Z[k] < R - i + 1) Z[i] = Z[k];
            else {
                L = i;
                while (R < n && s[R - L] == s[R]) R++;
                Z[i] = R - L; R--;
            }
        }
    }
    return Z;
}
 
vector<ll> seive(1000000, 1);
void precom(vector<ll>& seive) {
    for (ll i = 2; i * i < 1e6; i++) {
        if (seive[i] == 0) continue;
        for (ll j = 2 * i; j < 1e6; j += i) {
            seive[j] = 0;
        }
    }
}
 
bool isp(ll n) {
    if (seive[n] != 0) return 1;
    return 0;
}
 
ll MEX(vector<ll> v, ll n) {
    unordered_set<ll> s;
    for (ll i = 0; i < n; ++i) s.insert(v[i]);
    for (ll i = 0; i <= n; ++i) {
        if (s.find(i) == s.end()) return i;
    }
    return n + 1;
}
 
bool isPalindrome(string s) {
    ll i = 0, j = s.size() - 1;
    for (; i <= j; i++, j--) {
        if (s[i] != s[j]) return 0;
    }
    return 1;
}
 
void sortv(vector<ll>& v) {
    sort(v.begin(), v.end());
}
 
void revv(vector<ll>& v) {
    reverse(v.begin(), v.end());
}
 
ll binpow(ll a, ll b, ll m) {
    if (b == 0) return 1;
    if (b % 2 == 1) {
        return a * binpow(a, b - 1, m) % m;
    } else {
        ll x = binpow(a, b / 2, m);
        return (x * x) % m;
    }
}
 
ll inverse(ll a, ll m) {
    return binpow(a, m - 2, m) % m;
}
 
ll n, m;
vector<vector<char>> v, movee;
vector<vector<pair<ll,ll>>> back;
vector<vector<ll>> dist;
 
void solve() {
    cin >> n >> m;
    v.assign(n, vector<char>(m));
    movee.assign(n, vector<char>(m));
    back.assign(n, vector<pair<ll,ll>>(m));
    dist.assign(n, vector<ll>(m, 1e9));
 
    pair<ll,ll> start, end;
    for (ll i = 0; i < n; i++) {
        string s; cin >> s;
        for (ll j = 0; j < m; j++) {
            v[i][j] = s[j];
            if (v[i][j] == 'A') start = {i, j};
            if (v[i][j] == 'B') end = {i, j};
        }
    }
 
    dist[start.first][start.second] = 0;
    queue<pair<ll,ll>> q;
    q.push(start);
 
    ll dx[4] = {-1, 1, 0, 0};
    ll dy[4] = {0, 0, 1, -1};
    char dr[4] = {'U', 'D', 'R', 'L'};
 
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        ll r = node.first, c = node.second;
        for (ll i = 0; i < 4; i++) {
            ll nr = r + dx[i], nc = c + dy[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && (v[nr][nc] == '.' || v[nr][nc] == 'B') && dist[nr][nc] == (ll)1e9) {
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
                back[nr][nc] = {r, c};
                movee[nr][nc] = dr[i];
            }
        }
    }
 
    if (dist[end.first][end.second] != (ll)1e9) {
        yes;
        cout << dist[end.first][end.second] << "\n";
        string ans;
        while (end != start) {
            ans.push_back(movee[end.first][end.second]);
            end = back[end.first][end.second];
        }
        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    } else {
        no;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
