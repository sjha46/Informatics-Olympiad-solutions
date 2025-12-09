#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 1000010;
ll cnt = 0;
const vector<bool> visited(MAXN, false);
vector<bool> vis(MAXN);
void dfs(vector<vector<ll>> &graph, vector<ll> &museum, ll source) {
    cnt += museum[source];
    vis[source] = true;
    for(ll i : graph[source]) {
        if(!vis[i]) dfs(graph, museum, i);
    }
}
int main() {
    ll t;
    cin>>t;
    while(t--) {
	ll n, m, k;
	cin>>n>>m>>k;
	vector<vector<ll>> graph(n+1);
	for(ll i=0; i<m; i++) {
	    ll u, v;
	    cin>>u>>v;
	    graph[u].push_back(v);
	    graph[v].push_back(u);
	}
	vector<ll> mus(n+1);
	for(ll i=1; i<=n; i++) cin>>mus[i];
	vector<ll> ans;
	for(ll i=1; i<=n; i++) {
	    cnt = 0;
	    if(!vis[i]) {
	        dfs(graph, mus, i);
	        ans.push_back(cnt);
	    }
	}
	    ll x = ans.size();
	    if(k > x) cout<<"-1"<<endl;
	    else {
	        ll sol = 0;
	        sort(ans.rbegin(), ans.rend());
	        for(ll i=0; i<(k+(k%2))/2; i++) {
	            sol += ans[i];
	        }
	        for(ll i=1; i<=(k/2); i++) {
	            sol += ans[x - i];
	        }
	        cout << sol << endl;
	    }
	    ans.clear();
	    vis = visited;
    }
}