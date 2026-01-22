#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(auto &u : a) cin >> u;
    while(q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int ans = 1;
        for(int i=l; i<=r; i++) {
            if(a[i] == ans) {
                ans++;
            }
        }
        cout << ans;
        if(q != 0) cout << ' ';
    }
    cout << endl;
}
int main() {
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}