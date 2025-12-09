#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000001;
int COUNT = 0;
int r, c, n;
set<pair<int, int>> vis;
set<pair<int, int>> graph;
set<pair<int, int>> graph2;
bool valid(int x, int y) {
    if(x < 1 || x > r || y < 1 || y > c) return false;
    if(!graph.count({x, y}) || vis.count({x, y})) return false;
    return true;
}
void dfs(int x, int y) {
    vis.insert({x, y});
    COUNT += 4;
    graph2.erase({x, y});
    if(graph.count({x-1, y})) {
        COUNT--;
        if(valid(x-1, y)) dfs(x-1, y);
    }
    if(graph.count({x, y-1})) {
        COUNT--;
        if(valid(x, y-1)) dfs(x, y-1);
    }
    if(graph.count({x+1, y})) {
        COUNT--;
        if(valid(x+1, y)) dfs(x+1, y);
    }
    if(graph.count({x, y+1})) {
        COUNT--;
        if(valid(x, y+1)) dfs(x, y+1);
    }
}
int main() {
	cin >> r >> c >> n;
	for(int i=0; i<n; i++) {
	    int a, b;
	    cin>>a>>b;
	    graph.insert({a, b});
	    graph2.insert({a, b});
	}
	int x, y, ans=0;
	while(!graph2.empty()) {
	    tie(x, y) = *graph2.begin();
	    COUNT = 0;
	    dfs(x, y);
	    ans = max(COUNT, ans);
	    tie(x, y) = *graph2.begin();
	}
	cout << ans << endl;
	return 0;
}