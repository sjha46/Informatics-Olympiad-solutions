// Created by: shivankjha46
// Problem: INOI2201
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout << "Yes\n";
#define no cout << "No\n";
const ll MOD = 998244353; // 1e9 + 7;
const ll INF = 1e18;
const ll MAXN = 2e5 + 5;
// vector<bool> prime(MAXN, true);
// vector<ll> fact(MAXN);
void factorial() {
    // fact[0] = 1;
    // for(ll i=1; i<MAXN; i++) fact[i] = (i * fact[i-1]) % MOD;
}
void sieve() {
    // prime[0] = prime[1] = false;
    // for(ll i=2; i<MAXN; i++) {
        // if(prime[i]) {
            // for(ll j=i*i; j<MAXN; j+=i) {
                // prime[j] = false;
            // }
        // }
    // }
}
ll power(ll a, ll b, ll m) {
    ll res = 1;
    while(b) {
        if(b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}
ll inv(ll a, ll p) {
    return power(a, p-2, p);
}
void solve() {
   int n, m;
   cin >> n >> m;
   vector<ll> a(n+1);
   for(int i=1; i<=n; i++) cin >> a[i];
   sort(a.begin(), a.end());
   vector<array<ll, 3>> tmp(m+1);
   for(int i=1; i<=m; i++) cin >> tmp[i][0] >> tmp[i][1] >> tmp[i][2];
   sort(tmp.begin(), tmp.end());
   vector<ll> b(m+1), s(m+1), e(m+1);
   for(int i=1; i<=m; i++) b[i] = tmp[i][0], s[i] = tmp[i][1], e[i] = tmp[i][2];
   vector<vector<ll>> dp(m+1, vector<ll>(n+1, INF));
   dp[0][0] = 0;
   vector<vector<ll>> pref(m+1, vector<ll>(n+1, 0));
   for(int i=1; i<=m; i++) {
       for(int j=1; j<=n; j++) {
           pref[i][j] = pref[i][j-1] + abs(a[j] - b[i]);
       }
   }
   for(int i=1; i<=m; i++) {
       deque<pair<ll, ll>> dq;
       for(int j=s[i]; j<=n; j++) {
           ll cost = pref[i][j - s[i]] - dp[i-1][j - s[i]];
           while(dq.size() && (cost > dq.back().second)) dq.pop_back();
           dq.push_back({j - s[i], cost});
           while(dq.front().first < (j - e[i])) dq.pop_front();
           dp[i][j] = min(dp[i][j], (pref[i][j] - dq.front().second));
       }
   }
   if(dp[m][n] >= INF) cout << -1 << endl;
   else cout << dp[m][n] << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}
