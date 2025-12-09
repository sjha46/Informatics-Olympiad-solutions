#include <bits/stdc++.h>
using namespace std;
#define ll long long;
ll n, k;
bool relative(unordered_set<ll> a, unordered_set<ll> b) {
    ll cnt = 0;
    for(auto it = a.begin(); it != a.end(); it++) {
        if(b.find(*it) != b.end()) cnt++;
    }
    return (cnt >= k);
}
int main() {
	cin>>n>>k;
	vector<unordered_set<ll>> a(n);
	for(ll i=0; i<n; i++) {
	    ll c;
	    cin >> c;
	    for(ll j=0; j<c; j++) {
	        ll x;
	        cin>>x;
	        a[i].insert(x);
	    }
	}
	vector<vector<ll>> graph(n);
	for(ll i=0; i<n; i++) {
	    for(ll j=i+1; j<n; j++) {
	        if(relative(a[i], a[j])) {
	            graph[i].push_back(j);
	            graph[j].push_back(i);
	        }
	    }
	}
	queue<ll> q;
	vector<bool> vis(n, false);
	vis[0] = true;
	q.push(0);
	ll cnt = 1;
	while(!q.empty()) {
	    ll s = q.front(); 
	    q.pop();
	    for(ll i : graph[s]) {
	        if(!vis[i]) {
	            cnt++;
	            q.push(i);
	            vis[i] = true;
	        }
	    }
	}
	cout << cnt << endl;
	return 0;
}