#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define F find
#define S second
//ALL PAIR SHORTEST PATH (APSP)
//relax every through and intermidate node "K"
//time complexity is (N^3)
//using dijikstra-> (V*(V+E)*log(E))=V^3log(V)
//if theres negative edge use Belman ford (relax every node (|V|-1)) times to check whethere there is negative cycle or not do it one more time if the distance is decreasing that means it contains a negative cycle 
//time complexity using bellman ford is (|V|^4)
//it is basically using DP to calculate 

vector<vector<ll>> dis;
ll n,m;
void floyd(){

 for(ll k=1; k<=n; k++){
        for(ll i=1; i<=n; i++){
            for(ll j=1; j<=n; j++){
                if(dis[i][j]>(dis[i][k]+dis[k][j])){
                    dis[i][j]=(dis[i][k]+dis[k][j]);
                }
            }
        }
 }

}



int main(){
    cin>>n>>m;
     dis.resize(n+1,vector<ll>(n+1,1e18));
    for(ll i=0; i<m; i++){
     ll u,v,d;
     cin>>u>>v>>d;
     dis[u][v]=min(dis[u][v],d) ;
    }
     for(ll i=1; i<=n; i++){
         dis[i][i]=0;
    }
    floyd();

}