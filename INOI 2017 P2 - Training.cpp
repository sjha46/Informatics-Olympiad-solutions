#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, in;
ll sum(ll x) {
    ll ans = 0;
    while(x > 0) {
        ans += (x % 10);
        x /= 10;
    }
    return (ans * ans * ans);
}
int main() {
    cin>>n>>in;
    vector<ll> e(n);
    for(ll i=0; i<n; i++) cin>>e[i];
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    vector<ll> s(n);
    s[0] = in;
    for(ll i=1; i<n; i++) s[i] = s[i-1] + sum(s[i-1]);
    for(ll i=0; i<n; i++) dp[n-1][i] = (s[i] * e[n-1]);
    for(ll i=n-2; i>=0; i--) {
        for(ll j=0; j<=i; j++) {
            dp[i][j] = max(dp[i+1][j+1], (s[j] * e[i]) + dp[i+1][j]);
        }
    }
    cout << dp[0][0] << endl;
    return 0;
}