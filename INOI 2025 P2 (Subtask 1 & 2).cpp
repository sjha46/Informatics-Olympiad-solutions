#include <bits/stdc++.h>
using namespace std;
#define ll long long
void dfs(vector<vector<ll>> &dist, vector<vector<pair<int, ll>>> &tree, int node, int par, int start) {
    for(auto &child : tree[node]) {
        if(child.first == par) continue;
        dist[start][child.first] = dist[start][node] + child.second;
        dfs(dist, tree, child.first, node, start);
    }
}
void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<pair<int, ll>>> tree(n);
    for(int i=0; i<n-1; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--, v--;
        tree[u].push_back({v, w});
        tree[v].push_back({u, w});
    }
    vector<vector<ll>> dist(n, vector<ll>(n, 0));
    for(int i=0; i<n; i++) dfs(dist, tree, i, -1, i);
    vector<ll> d;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            d.push_back(dist[i][j]);
        }
    }
    sort(d.begin(), d.end());
    while(q--) {
        ll k;
        cin >> k;
        auto it1 = lower_bound(d.begin(), d.end(), k);
        auto it2 = upper_bound(d.begin(), d.end(), 2*k);
        if(it1 == it2) cout << 0;
        else cout << 1;
    }
    cout << endl;
}
int main() {
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}