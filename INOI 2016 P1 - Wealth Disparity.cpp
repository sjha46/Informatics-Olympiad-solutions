#include <bits/stdc++.h>
using namespace std;
vector<int> a;
vector<vector<int>> child;
vector<int> mn1, mn2;
void dfs(int node) {
    if((child[node]).empty()) {
        mn2[node] = a[node];
    }
    else {
        for(auto &u : child[node]) {
            dfs(u);
            mn1[node] = min(mn1[node], mn1[u]);
            mn2[node] = min(mn2[node], mn1[u]);
        }
    }
}
int main() {
	int n;
	cin >> n;
	a.resize(n);
	child.resize(n);
	for(auto &u : a) cin >> u;
	mn1 = a;
	mn2.resize(n, 1e9);
	int root;
	for(int i=0; i<n; i++) {
	    int p;
	    cin >> p;
	    p--;
	    if(p != -2) {
	        child[p].push_back(i);
	    }
	    else {
	        root = i;
	    }
	}
	dfs(root);
	int ans = -1e9;
	for(int i=0; i<n; i++) ans = max(ans, a[i] - mn2[i]);
	cout << ans << endl;
}