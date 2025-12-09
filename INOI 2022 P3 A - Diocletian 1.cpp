#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
vector<vector<int>> adj(MAXN);
vector<int> d(MAXN); 
vector<int> pa(MAXN);
void dfs(int node, int par) {
    pa[node] = par;
    for(auto &child : adj[node]) {
        if(child == par) continue;
        dfs(child, node);
    }
}
void dfs2(int node, int par, vector<int> &ans) {
    ans[node] = 1;
    for(auto &child : adj[node]) {
        if(child == par) continue;
        dfs2(child, node, ans);
    }
}
int main() {
	int n, m, p;
	cin >> n >> m >> p;
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << p << endl;
    if(m == (n - 1)) {
        dfs(0, -1);
        for(int i=1; i<n; i++) {
            vector<int> ans(n, 0);
            dfs2(i, pa[i], ans);
            for(auto &u : ans) cout << u;
            cout << endl;
        }
    }
    else {
        for(int i=1; i<=m; i++) {
            string s;
            for(int j=n-1; j>=0; j--) {
                if(j < 12) {
                    if(i & (1 << j)) {
                        s += '1';
                    }
                    else {
                        s += '0';
                    }
                }
                else {
                    s += '0';
                }
            }
            cout << s << endl;
        }
    }
    return 0;
}
