#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<bool> vis;
vector<int> t, mn;
int timer; 
bool flag = false;
void dfs(int node, int par, vector<vector<int>> graph) {
    vis[node] = true;
    t[node] = mn[node] = ++timer;
    bool p = false;
    for(auto &child : graph[node]) {
        if(child == par && (!p)) {
            p = true;
            continue;
        }
        if(vis[child]) {
            mn[node] = min(mn[node], t[child]);
        }
        else {
            dfs(child, node, graph);
            mn[node] = min(mn[node], mn[child]);
            if(mn[child] > t[node]) {
                flag = true;
            }
        }
    }
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<pair<pair<int, int>, int>> graph;
	for(int i=0; i<n-1; i++) {
	    int u, v;
	    cin >> u >> v;
	    u--, v--;
	    graph.push_back({{u, v}, 1e9});
	}
	if(m < n) {
	    cout << -1 << endl;
	    return 0;
	}
	for(int i=0; i<(m - (n-1)); i++) {
	    int u, v, w;
	    cin >> u >> v >> w;
	    u--, v--;
	    graph.push_back({{u, v}, w});
	}
	int q;
	cin >> q;
	int l = -1, r = 5e8, mid;
	int ans = -1;
	while(l <= r) {
	    int mid = (l + r) >> 1;
	    vector<vector<int>> graph2(n);
	    for(const auto &x : graph) {
	        if(x.second >= mid) {
	            int u = x.first.first, v = x.first.second;
	            graph2[u].push_back(v);
	            graph2[v].push_back(u);
	        }
	    }
	    flag = false;
	    timer = 0;
	    vis.assign(n, false);
	    t.assign(n, -1);
	    mn.assign(n, -1);
	    for(int i=0; i<n; i++) {
	        if(!vis[i]) dfs(i, -1, graph2);
	    }
 	    if(!flag) {
	        ans = mid;
	        l = mid + 1;
	    }
	    else {
	        r = mid - 1;
	    }
	    graph2.clear(); 
	    vis.resize(n, false);
	}
	cout << ans << endl;
    return 0;
}
