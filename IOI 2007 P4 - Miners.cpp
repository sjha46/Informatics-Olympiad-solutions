// Created by: shivankjha46
// Problem:
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
int cnt(int a, int b, int c) {
    set<int> s = {a, b, c};
    s.erase(0);
    return s.size();
}
void solve() {
   int n;
   cin >> n;
   string s;
   cin >> s;
  vector<vector<vector<vector<int>>>> next(4, vector<vector<vector<int>>>(4, vector<vector<int>>(4, vector<int>(4))));
  vector<vector<vector<vector<int>>>> cur(4, vector<vector<vector<int>>>(4, vector<vector<int>>(4, vector<int>(4))));
   for(int i=n-1; i>=0; i--) {
       for(int a=0; a<4; a++) {
           for(int b=0; b<4; b++) {
               for(int c=0; c<4; c++) {
                   for(int d=0; d<4; d++) {
                       if(s[i] == 'B') {
                           cur[a][b][c][d] = max(next[b][1][c][d] + cnt(a, b, 1), next[a][b][d][1] + cnt(c, d, 1));
                       }
                       else if(s[i] == 'F') {
                           cur[a][b][c][d] = max(next[b][2][c][d] + cnt(a, b, 2), next[a][b][d][2] + cnt(c, d, 2));
                       }
                       else {
                           cur[a][b][c][d] = max(next[b][3][c][d] + cnt(a, b, 3), next[a][b][d][3] + cnt(c, d, 3));
                       }
                   }
               }
           }
       }
       next = cur;
   }
   cout << cur[0][0][0][0] << endl;
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
