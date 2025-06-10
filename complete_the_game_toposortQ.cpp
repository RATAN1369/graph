#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const ll MOD = 1e9+7;

int main() {
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> adj(n+1);
    vector<ll> indegree(n+1, 0), dp(n+1, 0);

    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b);
        indegree[b]++;
    }

    queue<ll> q;
    for (ll i = 1; i <= n; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    dp[1] = 1;

    while (!q.empty()) {
        ll u = q.front(); q.pop();
        for (auto v : adj[u]) {
            dp[v] = (dp[v] + dp[u]) % MOD;
            indegree[v]--;
            if (indegree[v] == 0) q.push(v);
        }
    }

    cout << dp[n] << "\n";
    return 0;
}
//  Concept Behind the Solution:
// This is a classic Graph + Dynamic Programming problem on a DAG (Directed Acyclic Graph).

// 💡 Step-by-step Explanation:
// Model the game as a graph:

// Levels are nodes.

// Teleporters are directed edges (from a to b).

// Goal:

// Find number of distinct paths from node 1 to node n.

// Key properties:

// No cycles ⇒ Graph is a DAG.

// We can use Topological Sort + DP to solve this efficiently.

// DP idea:

// Let dp[i] be the number of ways to reach level i from level 1.

// Start with dp[1] = 1 because there's only one way to be at the starting level.

// For every outgoing edge from a node u to v, we do:

// Copy
// Edit
// dp[v] += dp[u]
// Why Topological Sort?

// We must process a node only after all its dependencies (incoming nodes) are processed.

// Topological sorting ensures this order in a DAG.