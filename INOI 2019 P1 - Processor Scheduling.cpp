#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 5005;
const ll INF = 1e17;
ll q[MAXN];
ll dp[MAXN][MAXN];
vector<pair<ll, ll>> p(MAXN, {0, 0});
int main() {
    int t;
    cin >> t;
    while(t--) {
	    int n, m;
    	cin >> n >> m;
	    for(int i=1; i<=n; i++) cin >> q[i];
    	for(int i=1; i<=m; i++) cin >> p[i].second;
    	for(int i=1; i<=m; i++) cin >> p[i].first;
	    sort(p.begin() + 1, p.begin() + m + 1);
    	p[m+1] = {1e15, 1e15};
    	for(int i=0; i<=n; i++) {
    	    for(int j=0; j<=m; j++) {
    	        dp[i][j] = 1e15;
    	    }
    	}
    	dp[0][0] = 0;
	    for(int i=0; i<=n; i++) {
	        for(int j=0; j<=m; j++) {
	            if(j > 0) dp[i][j] = (dp[i][j-1] > p[j].first ? INF : max(dp[i][j-1] + p[j].second, p[j].first));
	            if((i > 0) && ((dp[i-1][j] + q[i]) < p[j+1].first)) dp[i][j] = min(dp[i][j], dp[i-1][j] + q[i]);
	        }
	    }
	    cout << (dp[n][m] > 1e15? -1 : dp[n][m]) << endl;
    }
    return 0;
}