// Created by: shivankjha46
// Problem: IOI095
#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++) cin >> a[i];
    vector<int> w(m+1);
    for(int i=1; i<=m; i++) cin >> w[i];
    set<int> park;
    for(int i=1; i<=n; i++) park.insert(i); 
    deque<int> dq;
    bool full = false;
    int ans = 0;
    vector<int> slot(m+1);
    for(int i=0; i<(2*m); i++) {
        int x;
        cin >> x;
        if(x > 0) {
            if(full) {
                dq.push_back(x);
            }
            else {
                int idx = *park.begin();
                slot[x] = idx;
                park.erase(park.begin());
                ans += (a[idx] * w[x]);
            }
        }
        else {
            x = -x;
            if(full) {
                if(dq.empty()) {
                    park.insert(slot[x]);
                }
                else {
                    int next = dq.front();
                    dq.pop_front();
                    ans += (a[slot[x]] * w[next]);
                    slot[next] = slot[x];
                }
            }
            else {
                park.insert(slot[x]);
            }
        }
        if(park.empty()) full = true;
        else full = false;
    }
    cout << ans << endl;
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
