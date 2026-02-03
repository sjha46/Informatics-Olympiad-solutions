// Created by: shivankjha46
// Problem:
#include <bits/stdc++.h>
using namespace std;
void solve() {
   int n, q;
   cin >> n >> q;
   vector<int> a(n+1);
   for(int i=1; i<=n; i++) cin >> a[i];
   vector<vector<int>> occ(n+1);
   for(int i=1; i<=n; i++) occ[a[i]].push_back(i);
   vector<vector<int>> lift(n+1, vector<int>(18));
   for(int i=1; i<=n; i++) {
       int ans;
       if(a[i] == n) ans = n+1;
       else {
           auto it = lower_bound(occ[a[i] + 1].begin(), occ[a[i] + 1].end(), i);
           if(it == occ[a[i] + 1].end()) ans = n+1;
           else ans = *it;
       }
       lift[i][0] = ans;
   }
   for(int j=1; j<18; j++) {
       for(int i=1; i<=n; i++) {
           if(lift[i][j-1] == (n+1)) lift[i][j] = n+1;
           else lift[i][j] = lift[lift[i][j-1]][j-1];
       }
   }
   vector<int> cur = occ[1];
   while(q--) {
       int l, r;
       cin >> l >> r;
       auto it = lower_bound(cur.begin(), cur.end(), l);
       if(it == cur.end()) {
           cout << 1 << ' ';
           continue;
       }
       int idx = *it;
       if(idx > r) {
           cout << 1 << ' ';
           continue;
       }
       int ans = 0;
       for(int i=17; i>=0; i--) {
           if(lift[idx][i] <= r) {
               ans += (1 << i);
               idx = lift[idx][i];
           }
       }
       cout << ans + 2 << ' ';
   }
   cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}