#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 200010;
vector<vector<pair<ll, ll>>> lift(MAXN, vector<pair<ll, ll>>(18, {0, 0}));
vector<ll> d(MAXN);
void dfs(ll node, ll par, vector<vector<pair<ll, ll>>> &adj) {
    d[node] = d[par] + 1;
    for(auto &u : adj[node]) {
        if(u.first == par) continue;
        dfs(u.first, node, adj);
        lift[u.first][0] = {node, u.second};
    }
}
void lifting(ll n) {
    for(int j=1; j<18; j++) {
        for(int i=1; i<=n; i++) {
            ll a = lift[i][j-1].first, b = lift[i][j-1].second;
            lift[i][j] = {lift[a][j-1].first, b + lift[a][j-1].second};
        }
    }
}
ll lca(ll a, ll b) {
    if(d[a] > d[b]) swap(a, b);
    for(int i=17; i>=0; i--) {
        if(d[lift[b][i].first] >= d[a]) {
            b = lift[b][i].first;
        }
    }
    if(a == b) return a;
    for(int i=17; i>=0; i--) {
        if(lift[a][i].first != lift[b][i].first) {
            a = lift[a][i].first;
            b = lift[b][i].first;
        }
    }
    return lift[a][0].first;
}
ll dist(ll a, ll b) {
    if(a == b) return 0;
    ll x = lca(a, b);
    ll ans = 0;
    for(int i=17; i>=0; i--) {
        if(d[lift[a][i].first] >= d[x]) {
            ans += lift[a][i].second;
            a = lift[a][i].first;
        }
    }
    for(int i=17; i>=0; i--) {
        if(d[lift[b][i].first] >= d[x]) {
            ans += lift[b][i].second;
            b = lift[b][i].first;
        }
    }
    return ans;
}
vector<ll> parent(MAXN), sz(MAXN);
void init(ll n) {
    for(int i=1; i<=n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}
ll find(ll n) {
    if(n == parent[n]) return n;
    return parent[n] = find(parent[n]);
}
void unite(ll a, ll b) {
    a = find(a), b = find(b);
    if(a != b) {
        if(sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}
int main() {
	ll t;
	cin >> t;
	while(t--) {
	    ll n, q;
	    cin >> n >> q;
	    vector<vector<pair<ll, ll>>> adj(n+1);
	    vector<pair<ll, pair<ll, ll>>> edges(n-1);
	    vector<ll> wt(n-1);
	    vector<pair<ll, ll>> info(n+1);
	    for(int i=1; i<=n; i++) info[i] = {i, i};
	    for(int i=1; i<n; i++) {
	        ll u, v, w;
	        cin >> u >> v >> w;
	        adj[u].push_back({v, w});
	        adj[v].push_back({u, w});
	        edges[i-1] = {w, {u, v}};
	        wt[i-1] = w;
	    }
	    dfs(1, 0, adj);
	    lifting(n);
	    init(n);
	    sort(wt.begin(), wt.end());
	    sort(edges.begin(), edges.end());
	    vector<pair<ll, ll>> ar(q);
	    for(int i=0; i<q; i++) {
	        ll x;
	        cin >> x;
	        ar[i] = {x, i};
	    }
	    sort(ar.begin(), ar.end());
	    vector<ll> ans(q, 0);
	    ll idx = 0, mx = 0;
	    for(auto &k : ar) {
	        while((idx < (n - 1)) && (wt[idx] < k.first)) {
	            ll u = edges[idx].second.first, v = edges[idx].second.second;
	            ll a = find(u), b = find(v);
	            unite(u, v);
	            ll p = info[a].first;
	            ll q = info[a].second;
	            ll r = info[b].first;
	            ll s = info[b].second;
	            ll v1 = dist(p, q), v2 = dist(p, r), v3 = dist(p, s), v4 = dist(q, r), v5 = dist(q, s), v6 = dist(r, s);
	            ll cur = max({v1, v2, v3, v4, v5, v6});
	            ll x = find(u);
	            if(v1 == cur) info[x] = {p, q};
	            else if(v2 == cur) info[x] = {p, r};
	            else if(v3 == cur) info[x] = {p, s};
	            else if(v4 == cur) info[x] = {q, r};
	            else if(v5 == cur) info[x] = {q, s};
	            else info[x] = {r, s};
	            mx = max(mx, cur);
	            idx++;
	        }
	        auto it = lower_bound(wt.begin(), wt.end(), k.first);
	        if((it != wt.end()) && (*it <= (2 * k.first))) {
	            ans[k.second] = 1;
	        }
	        else if(mx >= k.first) {
	            ans[k.second] = 1;
	        } 
	    }
	    for(auto &u : ans) cout << u;
	    cout << endl;
	}
	return 0;
}
