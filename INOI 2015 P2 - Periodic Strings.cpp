#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	int n;
	ll m;
	cin >> n >> m;
	vector<ll> power(n+1), dp(n+1, 0);
	power[0] = 1;
	for(int i=1; i<=n; i++) power[i] = (2 * power[i-1]) % m;
	for(int i=2; i<=n; i++) {
	    if(n % i == 0) {
	        for(int j=1; j<i; j++) {
	            if(i % j == 0) {
	                dp[i] = (dp[i] + power[j] - dp[j] + m) % m;
	            }
	        }
	    }
	}
	cout << ((power[n] - dp[n] + m) % m) << endl;
}
