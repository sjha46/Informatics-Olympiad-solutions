#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;
int main() {
int t;
cin>>t;
while(t--) {
int k, n;
cin>>k>>n;
ll dp[4][n+1];
if(k==1) 
cout<<(n%3==0)<<endl;
else if(k==2) {
dp[2][1] = 0;
dp[2][2] = 1;
dp[2][3] = 1;
for(int i = 4; i <= n; i++) {
dp[2][i] = ((dp[2][i-2] + dp[2][i-3]) % mod);
}
cout<<dp[2][n]<<endl;
}
else {
ll sp[n+1];
ll rp[n+1];
dp[3][1] = 1;
dp[3][2] = 1;
dp[3][3] = 2;
sp[1] = 0;
sp[2] = 0;
sp[3] = 1;
rp[0] = 0;
rp[1] = 0;
rp[2] = 1;
rp[3] = 1;
for(int i=4; i<=n; i++) {
dp[3][i] = ((dp[3][i-1] + dp[3][i-3] + 2*sp[i-3]) % mod);
sp[i] = ((dp[3][i-3] + sp[i-3] + rp[i-4]) % mod);
rp[i] = ((dp[3][i-2] + rp[i-3]) % mod);
}
cout<<dp[3][n]<<endl;
}
}
return 0;
}

