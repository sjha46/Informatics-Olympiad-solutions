#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 5e5 + 5;
struct chain {
    ll both = 0, none = 0, down = 0, up = 0;
};

chain combine(chain c1, chain c2) {
    chain res;
    res.none = max(c1.up + c2.none, c1.none + max(c2.down, c2.none));
    res.both = max(c1.down + max(c2.both, c2.up), c1.both + c2.up);
    res.up = max(c2.up + max(c1.none, c1.up), c2.both + c1.none);
    res.down = max(c1.down + max(c2.none, c2.down), c1.both + c2.none);
    return res;
}
chain inverse(chain c) {
    chain res;
    res.none = c.none;
    res.both = c.both;
    res.up = c.down;
    res.down = c.up;
    return res;
}
vector<vector<int>> tree;
vector<vector<int>> lift;
vector<vector<chain>> dp;
vector<int> in, out;
vector<chain> chains;
int tim = 0;
void dfs(int node, int par) {
    in[node] = tim++;
    if(par != node) {
        lift[node][0] = par;
        dp[node][0] = chains[par];
        for(int i=1; i<19; i++) {
            lift[node][i] = lift[lift[node][i-1]][i-1];
            if(lift[node][i] == -1) break;
            dp[node][i] = combine(dp[node][i-1], dp[lift[node][i-1]][i-1]);
        }
    }
    for(auto &u : tree[node]) {
        if(u != par) {
            dfs(u, node);
        }
    }
    out[node] = tim++;
}
int anc(int u, int v) {
    if(u == -1 || v == -1) return -1;
    return ((in[u] <= in[v]) && (out[v] <= out[u]));
}
int lca(int u, int v) {
    if(anc(u, v)) {
        return u;
    }
    if(anc(v, u)) {
        return v;
    }
    for(int i=18; i>=0; i--) {
        if(anc(lift[u][i], v) == 0) u = lift[u][i];
    }
    return lift[u][0];
}
chain get(int u, int lca, bool inc) {
    chain res;
    if(u == lca && !inc) return res;
    else res = chains[u];
    for(int i=18; i>=0; i--) {
        if(lift[u][i] == -1) continue;
        if(in[lca] < in[lift[u][i]]) res = combine(res, dp[u][i]), u = lift[u][i];
        else if(inc && in[lca] == in[lift[u][i]]) res = combine(res, dp[u][i]), u = lift[u][i];
    }
    return res;
}
int main() {
	int n, q;
	cin >> n >> q;
	vector<ll> a(n);
	for(auto &u : a) cin >> u;
	tree.resize(n), chains.resize(n), in.resize(n), out.resize(n);
	lift = vector<vector<int>>(n, vector<int>(19, -1));
	dp = vector<vector<chain>>(n, vector<chain>(19));
	for(int i=0; i<n-1; i++) {
	    int u, v;
	    cin >> u >> v;
	    u--, v--;
	    tree[u].push_back(v);
	    tree[v].push_back(u);
	}
	for(int i=0; i<n; i++) chains[i].both = a[i];
	dfs(0, 0);
	while(q--) {
	    int a, b;
	    cin >> a >> b;
	    a--, b--;
	    int x = lca(a, b);
	    chain c1 = get(a, x, true);
	    chain c2 = inverse(get(b, x, false));
	    chain res = combine(c1, c2);
	    ll ans = max(max(res.both, res.none), max(res.up, res.down));
	    cout << ans << endl;
	}
}
