#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;

ll n, m;
vector<vector<ll>> dis;
vector<ll> arr, ans;

void floyd() {
    vector<bool> vis(n + 1, false);
    for (ll step = n - 1; step >= 0; step--) {
        ll k = arr[step];
        vis[k] = true;

        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }

        ll sum = 0;
        for (ll i = 1; i <= n; i++) {
            if (!vis[i]) continue;
            for (ll j = 1; j <= n; j++) {
                if (!vis[j]) continue;
                if (dis[i][j] < INF)
                    sum += dis[i][j];
            }
        }
        ans.push_back(sum);
    }
}

int main() {
    cin >> n;
    dis.assign(n + 1, vector<ll>(n + 1));
    arr.resize(n);

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            cin >> dis[i][j];
        }
    }

    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    floyd();
    reverse(ans.begin(), ans.end());

    for (auto it : ans)
        cout << it << " ";
    cout << endl;
}
