#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 5e5 + 5;
vector<vector<int>> tree(MAXN);
vector<int> bfs(int n, int a, int b) {
    vector<int> p(n, -1);
    vector<bool> vis(n, false);
    queue<int> q;
    q.push(a);
    while(!q.empty()) {
        int x = q.front();
        if(x == b) break;
        vis[x] = true;
        q.pop();
        for(auto &u : tree[x]) {
            if(!vis[u]) {
                q.push(u);
                p[u] = x;
            }
        }
    }
    vector<int> path;
    for(int i=b; i != -1; i = p[i]) {
        path.push_back(i);
    }
    reverse(path.begin(), path.end());
    return path;
}
int main() {
	int n, q;
	cin >> n >> q;
	vector<ll> v(n);
	for(auto &u : v) cin >> u;
	for(int i=0; i<n-1; i++) {
	    int u, v;
	    cin >> u >> v;
	    u--, v--;
	    tree[u].push_back(v);
	    tree[v].push_back(u);
	}
	while(q--) {
	    int a, b;
	    cin >> a >> b;
	    a--, b--;
	    if(a == b) {
	        cout << v[a] << endl;
	        continue;
	    }
	    vector<int> path = bfs(n, a, b);
	    vector<ll> x;
	    for(auto &u : path) {
	        x.push_back(v[u]);
	    }
	    vector<ll> dp(x.size());
	    dp[0] = x[0];
	    dp[1] = max(x[0], x[1]);
	    for(int i=2; i<x.size(); i++) {
	        dp[i] = max(dp[i-1], dp[i-2] + x[i]);
	    }
	    cout << dp[x.size() - 1] << endl;
	}
}
