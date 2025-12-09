#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;
vector<vector<ll>> price(236, vector<ll>(236, INF));
int main() {
	ll c, f;
	cin>>c>>f;
	for(ll i=1; i<=235; i++) price[i][i] = 0;
	for(ll i=0; i<f; i++) {
	    ll a, b, p;
	    cin>>a>>b>>p;
	    price[a][b] = p;
	    price[b][a] = p;
	}
	for(ll k=1; k<=c; k++) {
	    for(ll i=1; i<=c; i++) {
	        for(ll j=1; j<=c; j++) {
	            price[i][j] = min(price[i][j], (price[i][k] + price[j][k]));
	        }
	    }
	}
	ll BEST = -INF;
	for(ll i=1; i<=c; i++) {
	    for(ll j=1; j<=c; j++) {
	        BEST = max(BEST, price[i][j]);
	    }
	}
	cout << BEST << endl;
	return 0;
}
