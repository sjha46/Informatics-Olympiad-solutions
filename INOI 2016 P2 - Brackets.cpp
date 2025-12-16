#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9; 
int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n), b(n);
	for(auto &u : a) cin >> u;
	for(auto &u : b) cin >> u;
	vector<vector<int>> dp(n, vector<int>(n, 0));
	for(int le=n-1; le>=0; le--) {
	    for(int ri=le+1; ri<n; ri++) {
	        if(b[le] + k == b[ri]) {
	            dp[le][ri] = max(dp[le][ri], dp[le+1][ri-1] + a[le] + a[ri]);
	        }
	        for(int i=le; i<ri; i++) {
	            dp[le][ri] = max(dp[le][ri], dp[le][i] + dp[i+1][ri]);
	        }
	    }
	}
	cout << dp[0][n-1] << endl;
}
