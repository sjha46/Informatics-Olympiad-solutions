#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e9 + 1;
vector<ll> dp, a;
ll n, k;
void preprocess() {
    dp[0] = 0;
    dp[1] = a[0];
    for(ll i=2; i<n; i++) dp[i] = max(a[i-1] + dp[i-1], a[i-2] + dp[i-2]);
}
int main() {
	cin >> n >> k;
	a.resize(n);
	for(ll i=0; i<n; i++) cin>>a[i];
	k--;
	dp.resize(n);
	preprocess();
	if(k == n-1) {
	    cout << dp[n-1] << endl;
	    return 0;
	}
	vector<ll> ans(n);
	ans[k] = 0;
	ans[k+1] = a[k+1];
	for(ll i=k+2; i<n; i++) ans[i] = a[i] + max(ans[i-1], ans[i-2]);
	ll best = -INF;
	for(ll i=k; i<n; i++) best = max(best, ans[i] + dp[i]);
	cout << best << endl;
	return 0;
}