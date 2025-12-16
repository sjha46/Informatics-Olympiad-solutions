#include <bits/stdc++.h>
using namespace std;
int a, b;
vector<vector<pair<int, bool>>> adj;
vector<int> col;
bool dfs(int node, int cur) {
    col[node] = cur; 
    a += cur;
    b += !cur;
    for(auto &u : adj[node]) {
        if(col[u.first] != -1) {
            if(col[u.first] != (cur ^ u.second)) return false;
            continue;
        }
        if(!dfs(u.first, (cur ^ u.second))) return false;
    }
    return true;
}
void solve() {
	int n, m;
	cin >> n >> m;
	col.clear();
	adj.clear();
	col.resize(n, -1);
	adj.resize(n);
	for(int i=0; i<m; i++) {
	    int t, u, v;
	    cin >> t >> u >> v;
	    u--, v--;
	    adj[u].push_back(make_pair(v, (t == 1)));
	    adj[v].push_back(make_pair(u, (t == 1)));
	}
	bool flag = true;
	int ans = 0;
	for(int i=0; i<n; i++) {
	    if(col[i] != -1) continue;
	    a = 0, b = 0;
	    if(!dfs(i, 1)) {
	        flag = false;
	        break;
	    }
	    ans += max(a, b);
	}
	cout << (flag ? ans : -1) << endl;
}
int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}