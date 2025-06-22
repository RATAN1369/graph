    
   /*ratan_03*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define yes cout<<"YES"<<"\n"
#define no cout<<"NO"<<"\n"
#define one cout<<-1<<"\n"
#define M 1000000007
#define pb push_back
#define MP make_pair

long long int gcd(ll a , ll b){
    if(b==0) return a;
    else return gcd(b,a%b);
}

long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) { // If exp is odd
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp = exp / 2;
    }
    return result;
}
ll fact(int n){
    if(n==0) return 1;
    else return (n*fact(n-1))%M;
}
vector<int> calculateZ(string s) {
    int n = s.length();
    vector<int> Z(n);
    int L = 0, R = 0;

    for (int i = 1; i < n; i++) {
        if (i > R) {
            L = R = i;
            while (R < n && s[R-L] == s[R]) R++;
            Z[i] = R-L; R--;
        } else {
            int k = i-L;
            if (Z[k] < R-i+1) Z[i] = Z[k];
            else {
                L = i;
                while (R < n && s[R-L] == s[R]) R++;
                Z[i] = R-L; R--;
            }
        }
    }
    return Z;
}


void print(vector<ll> v){ //can use for debugging 
    ll n=v.size();
    for(ll i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
vector<ll> seive(1000000,1);
void precom(vector<ll>&seive){
    for(ll i=2; i*i<1e6; i++){
        if(seive[i]==0) continue;
        for(ll j=2*i; j<1e6; j+=i ){
            seive[j]=0;
        }
    }
}
bool isp(ll n){
    if(seive[n]!=0) return 1;
    return 0;
}
ll MEX(vector<ll> v,ll n)
{
    unordered_set<ll> s;
    for (ll i = 0; i < n; ++i)
    {
        s.insert(v[i]);
    }
    for (ll i = 0; i <= n; ++i)
    {
        if (s.find(i) == s.end())
        {
            return i;
        }
    }
    return n + 1;
}
bool isPalindrome(string s)
{
    ll i=0,j=s.size()-1;
    for(i,j; i<=j; i++,j--)
    {
        if(s[i]!=s[j]) return 0;
    }
    return 1;
}
void sortv(vector<ll> &v){
    sort(v.begin(),v.end());
    return;
}
void revv(vector<ll> &v){
    reverse(v.begin(),v.end());
    return;
}
ll binpow(ll a, ll b, ll m){
    if(b==0) return 1;
    if(b%2==1){
        return a*binpow(a,b-1,m)%m;
    }else{
        int x=binpow(a,b/2,m);
        return (x*x)%m;
    }
}
//fermats little theorem 
ll inverse(ll a,ll m){
    return binpow(a,m-2,m)%m;
}

// ll n; cin>>n;
// vector<ll> v(n);
// for(ll i=0; i<n; i++){
//     cin>>v[i];
// }
//sweep line algo
//binary search //two pointer 
int n;
vector<vector<char>> grid;
vector<vector<int>> dis;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
void bfs(pair<int, int> st) {
    queue<pair<int, pair<int, int>>> q;
    q.push({0, st});
    dis[st.first][st.second] = 0;

    while (!q.empty()) {
        auto node = q.front(); q.pop();
        int x = node.second.first;
        int y = node.second.second;
        int dist = node.first;

        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];

            if (xx >= 0 && xx < 2 && yy >= 0 && yy < n && dis[xx][yy] == 1e9) {
                if (grid[xx][yy] == '>' && yy + 1 < n && dis[xx][yy + 1] == 1e9) {
                    dis[xx][yy + 1] = dist + 1;
                    q.push({dis[xx][yy + 1], {xx, yy + 1}});
                } else if (grid[xx][yy] == '<' && yy - 1 >= 0 && dis[xx][yy - 1] == 1e9) {
                    dis[xx][yy - 1] = dist + 1;
                    q.push({dis[xx][yy - 1], {xx, yy - 1}});
                }
            }
        }
    }
}

void solve() {
    cin >> n;
    grid.assign(2, vector<char>(n));
    dis.assign(2, vector<int>(n, 1e9));

    for (int i = 0; i < 2; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++) {
            grid[i][j] = s[j];
        }
    }

    bfs({0, 0});
    if (dis[1][n - 1] != 1e9) yes;
    else no;
}






int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        solve();        
    }
    
}
