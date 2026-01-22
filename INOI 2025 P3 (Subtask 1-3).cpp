#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;
void dfs(vector<ll> &dp, vector<vector<int>> &tree, int node, int par) {
    ll sum = 0, prod = 1;
    for(auto &child : tree[node]) {
        if(child == par) continue;
        dfs(dp, tree, child, node);
        sum = (sum + dp[child]) % MOD;
        prod = (prod * (dp[child] + 1)) % MOD;
    }
    dp[node] = (sum + prod) % MOD;
}
void solve(int s) {
    if(s == 0) {
        int n;
        cin >> n;
        vector<int> p(n);
        vector<vector<int>> tree(n);
        for(int i=1; i<n; i++) {
            int x;
            cin >> x;
            x--;
            p[i] = x;
            tree[i].push_back(x);
            tree[x].push_back(i);
        }
        vector<ll> dp(n, 1);
        dfs(dp, tree, 0, -1);
        cout << dp[0] << endl;
    }
}
int main() {
	int t, s;
	cin >> t >> s;
	while(t--) solve(s);
	return 0;
}