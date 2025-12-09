#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll cnt = 0, mx = 0, mn = 1e6;
ll sum1 = 0, sum2 = 0;
bool flag = 0;
void dfs(ll s, vector<vector<ll>> &adj, vector<bool> &vis) {
    vis[s] = true;
    cnt++;
    mx = max(mx, s);
    mn = min(mn, s);
    for(ll i : adj[s]) {
        if(!vis[i]) dfs(i, adj, vis);
    }
}
vector<ll> dist(100007, 0);
void dfs2(ll s, vector<vector<ll>> &adj, vector<bool> &vis2) {
    vis2[s] = true;
    for(ll i : adj[s]) {
        if(!vis2[i]) {
            dist[i] = dist[s] + 1;
            if(!flag) sum1 += dist[i];
            else sum2 += dist[i];
            dfs2(i, adj, vis2);
        }
    }
}
int main() {
	ll t;
	cin>>t;
	while(t--) {
	    ll n, m;
	    cin >> n >> m;
	    vector<vector<ll>> adj(n+1);
	    for(ll i=0; i<m; i++) {
	        ll a, b;
	        cin >> a >> b;
	        adj[a].push_back(b);
	        adj[b].push_back(a);
	    }
	    vector<bool> vis(n+1, false);
	    vector<bool> vis2(n+1, false);
	    sum1 = 0, sum2 = 0;
	    for(ll i=1; i<=n; i++) {
	        if(!vis[i]) {
	            cnt = 0, mn = 1e6, mx = 0;
	            ll src;
	            dfs(i, adj, vis);
	            if(cnt % 2) { 
	               src = mx;
	               flag = 1; 
	               sum2++;
	            } 
	            else {
	                src = mn;
	                flag = 0;
	                sum1++;
	            }
	            dist[src] = 1;
	            dfs2(src, adj, vis2);
	        }
	    }
	    cout << sum1 << " " << sum2 << endl;
	}
	return 0;
}