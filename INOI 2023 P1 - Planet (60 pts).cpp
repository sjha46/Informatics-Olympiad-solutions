#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;
int main() {
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n), w(n);
	for(ll i=0; i<n; i++) cin >> a[i];
	for(ll i=0; i<n; i++) cin >> w[i];
	vector<vector<ll>> mx(n, vector<ll>(n));
	ll curr = 0;
	for(ll i=0; i<n; i++) {
	    for(ll j=i; j<n; j++) {
	        curr = max(curr, w[j]);
	        mx[i][j] = curr;
	    }
	    curr = 0;
	}
	vector<ll> pref(n);
	pref[0] = a[0];
	for(ll i=1; i<n; i++) pref[i] = pref[i-1] + a[i];
	vector<vector<ll>> dp(k+1, vector<ll>(n, INF));
	for(ll i=0; i<n; i++) dp[0][i] = mx[0][i] * pref[i];
	for(ll i=1; i<=k; i++) {
	    for(ll j=i; j<n; j++) {
	        for(ll l=i-1; l<j; l++) {
	            dp[i][j] = min(dp[i][j], dp[i-1][l] + (mx[l+1][j]*(pref[j]-pref[l])));
	        }
	    }
	}
	cout << dp[k][n-1] << endl;
	return 0;
}
