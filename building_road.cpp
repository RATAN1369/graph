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
vector<vector<ll>> adj;
vector<ll> vis;
void dfs(ll node){
  vis[node]=1;
  for(auto it: adj[node]){
    if(!vis[it]){
      dfs(it);
    }
  }
}
void solve() {
    cin >>n>>m;
    adj.assign(n+1,{});
    vis.assign(n+1,0);
    
    for(ll i=0; i<m; i++){
      ll u,v; cin>>u>>v;
      adj[u].pb(v);
      adj[v].pb(u);
    }
    ll cnt=0; vector<ll> ans;
    for(ll i=1; i<=n; i++){
      if(vis[i]==0){
        ans.pb(i);
    
        cnt++;
        dfs(i);
        
      }
    }
    cout<<cnt-1<<endl;
    for(ll i=1; i<ans.size(); i++){
      cout<<ans[i-1]<<" "<<ans[i]<<endl;
    }
    
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
