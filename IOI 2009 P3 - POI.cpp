// Created by: shivankjha46
// Problem: IOI093
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
bool compare(vector<int> a, vector<int> b) {
    if(a[0] > b[0]) return true;
    if(a[0] < b[0]) return false;
    if(a[1] > b[1]) return true;
    if(a[1] < b[1]) return false;
    if(a[2] < b[2]) return true;
    return false;
}
void solve() {
   int n, t, p;
   cin >> n >> t >> p;
   vector<vector<int>> scores(n, vector<int>(3));
   vector<int> unsolve(t);
   vector<vector<int>> solve(n);
   for(int i=0; i<n; i++) {
       for(int j=0; j<t; j++) {
           int x;
           cin >> x;
           if(x == 0) unsolve[j]++;
           if(x == 1) solve[i].push_back(j);
       }
   }
   for(int i=0; i<n; i++) {
       int score = 0;
       int ct = 0;
       for(auto &u : solve[i]) {
           score += unsolve[u];
           ct++;
       }
       scores[i] = {score, ct, i};
   }
   sort(scores.begin(), scores.end(), compare);
   for(int i=0; i<n; i++) {
       if(scores[i][2] == (p-1)) {
           cout << scores[i][0] << ' ' << i+1 << endl;
           return;
       }
   }
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