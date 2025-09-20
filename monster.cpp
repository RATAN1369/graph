#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define yes cout<<"YES"<<"\n"
#define no cout<<"NO"<<"\n"
#define one cout<<-1<<"\n"
#define M 1000000007
#define pb push_back

ll n,m;
vector<vector<char>> grid;
vector<vector<ll>> dis;
vector<vector<ll>> dis2;
vector<vector<pair<ll,ll>>> back;
vector<vector<char>> dir;


void solve() {
    cin>>n>>m;
    grid.assign(n,vector<char>(m));
    dir.assign(n,vector<char>(m));
    dis.assign(n,vector<ll>(m,1e9));  
    dis2.assign(n,vector<ll>(m,1e9));
    back.assign(n,vector<pair<ll,ll>>(m));
    queue<pair<ll,ll>> q;
    pair<ll,ll> st;
    for(ll i=0; i<n; i++){
       string s; cin>>s;
       for(ll j=0; j<m; j++){
         grid[i][j]=s[j];
         if(s[j]=='M') q.push({i,j}),dis[i][j]=0;
         if(s[j]=='A') st={i,j};
       }
    }
    ll dx[4]={-1,1,0,0};
    ll dy[4]={0,0,-1,1};
    char dr[4]={'U','D','L','R'};
    while(!q.empty()){
       ll r=q.front().first;
       ll c=q.front().second;
       q.pop();
       for(ll i=0; i<4; i++){
         ll nr=r+dx[i]; ll nc=c+dy[i];
         // ❌ condition wrong: you used grid[nr][nc]=='#' (walls).  
         // ✅ should allow moving on empty cells '.'
         if(nr>=0 && nc>=0 && nr<n && nc<m && dis[nr][nc]==1e9 && grid[nr][nc]=='.'){ 
           dis[nr][nc]=dis[r][c]+1;
           q.push({nr,nc});
         }
       }
    }

    // ❌ wrong queue type: you used queue<ll> but pushing pair
    // ✅ should be queue<pair<ll,ll>>
    queue<pair<ll,ll>> qq;  
    qq.push({st.first,st.second});
    dis2[st.first][st.second]=0;

    // ❌ you wrote while(!q.empty()) but should run BFS on qq
    while(!qq.empty()){  
       ll r=qq.front().first;
       ll c=qq.front().second;
       qq.pop();
       for(ll i=0; i<4; i++){
         ll nr=r+dx[i]; ll nc=c+dy[i];
         // ❌ condition wrong: grid[nr][nc]=='#' (walls) blocks movement
         // ✅ should allow '.' cells (and not 'M')
         if(nr>=0 && nc>=0 && nr<n && nc<m && (dis2[nr][nc]==1e9) && (grid[nr][nc]=='.')){ 
           dis2[nr][nc]=dis2[r][c]+1;
           back[nr][nc]={r,c};
           dir[nr][nc]=dr[i];
           qq.push({nr,nc});
         }
       }
    }

    //first row
    for(ll i=0; i<m; i++){
      if(grid[0][i]=='A'){
        cout<<"YES"<<endl;
        cout<<0<<endl;
        return;
      }
      if(grid[0][i]=='.' && dis2[0][i]<dis[0][i]){
          cout<<"YES"<<endl;
          pair<ll,ll> cur={0,i};
          string ans;
          while(cur!=st){
            ans.push_back(dir[cur.first][cur.second]);
            cur=back[cur.first][cur.second];
          }
          cout<<ans.size()<<endl;
          reverse(ans.begin(),ans.end());
          cout<<ans<<endl;
          return;  // ❌ missing return inside block
      }
    }
    
    for(ll i=0; i<m; i++){
      if(grid[n-1][i]=='A'){
        cout<<"YES"<<endl;
        cout<<0<<endl;
        return;
      }
      if(grid[n-1][i]=='.' && dis2[n-1][i]<dis[n-1][i]){
          cout<<"YES"<<endl;
          pair<ll,ll> cur={n-1,i};
          string ans;
          while(cur!=st){
            ans.push_back(dir[cur.first][cur.second]);
            cur=back[cur.first][cur.second];
          }
          cout<<ans.size()<<endl;
          reverse(ans.begin(),ans.end());
          cout<<ans<<endl;
          return; // ❌ missing return inside block
      }
    }
    for(ll i=0; i<n; i++){  // ❌ should loop over rows for left/right edges, not m
      if(grid[i][0]=='A'){
        cout<<"YES"<<endl;
        cout<<0<<endl;
        return;
      }
      if(grid[i][0]=='.' && dis2[i][0]<dis[i][0]){
          cout<<"YES"<<endl;
          pair<ll,ll> cur={i,0};
          string ans;
          while(cur!=st){
            ans.push_back(dir[cur.first][cur.second]);
            cur=back[cur.first][cur.second];
          }
          cout<<ans.size()<<endl;
          reverse(ans.begin(),ans.end());
          cout<<ans<<endl;
          return; // ❌ missing return inside block
      }
    }
    for(ll i=0; i<n; i++){  // ❌ should loop over rows for rightmost col
      if(grid[i][m-1]=='A'){
        cout<<"YES"<<endl;
        cout<<0<<endl;
        return;
      }
      if(grid[i][m-1]=='.' && dis2[i][m-1]<dis[i][m-1]){
          cout<<"YES"<<endl;
          pair<ll,ll> cur={i,m-1};
          string ans;
          while(cur!=st){
            ans.push_back(dir[cur.first][cur.second]);
            cur=back[cur.first][cur.second];
          }
          cout<<ans.size()<<endl;
          reverse(ans.begin(),ans.end());
          cout<<ans<<endl;
          return; // ❌ missing return inside block
      }
    }
    cout<<"NO"<<endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    solve();        
    return 0;
}
