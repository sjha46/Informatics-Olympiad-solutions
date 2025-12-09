#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool grid[305][305];
ll ans[305][305][305][2] = { };
int main() {
    ll r, c, D;
    cin >> r >> c >> D;
    for(ll i=1; i<=r; i++) {
        for(ll j=1; j<=c; j++) {
            cin>>grid[i][j];
        }
    }
    if(r == 1 && c == 1) {
        if(grid[0][0]) cout << "1" << endl;
        else cout << "0" << endl;
        return 0;
    }
    for(ll d=0; d<=D; d++) {
        ans[r][c][d][0] = 1;
        ans[r][c][d][1] = 1;
    }
    for(ll i=r; i>0; i--) {
        for(ll j=c; j>0; j--) {
            if(i == r && j == c) continue;
            if(grid[i][j]) {
                ans[i][j][D][0] = ans[i+1][j][1][1];
                ans[i][j][D][1] = ans[i][j+1][1][0];
                for(ll k=0; k<D; k++) {
                    ans[i][j][k][0] = (ans[i][j+1][k+1][0] + ans[i+1][j][1][1]) % 20011;
                    ans[i][j][k][1] = (ans[i][j+1][1][0] + ans[i+1][j][k+1][1]) % 20011;
                }
            }
        }
    }
    cout << ans[1][1][0][0] << endl;
    return 0;
}