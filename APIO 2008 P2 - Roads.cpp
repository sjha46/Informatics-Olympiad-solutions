#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20005;
vector<int> p1(MAXN), p2(MAXN);
void init(int n) {
    for(int i=0; i<n; i++) {
        p1[i] = p2[i] = i;
    }
}
int find1(int n) {
    if(p1[n] == n) return n;
    return p1[n] = find1(p1[n]);
}
int find2(int n) {
    if(p2[n] == n) return n;
    return p2[n] = find2(p2[n]);
}
bool union1(int a, int b) {
    a = find1(a);
    b = find1(b);
    if(a == b) return 0;
    p1[b] = a;
    return 1;
}
bool union2(int a, int b) {
    a = find1(a);
    b = find1(b);
    if(a == b) return 0;
    p1[b] = a;
    return 1;
}
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> s1, s2;
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(c) s2.push_back({a, b});
        else s1.push_back({a, b});
    }
    init(n);
    int ct = 0;
    vector<pair<pair<int, int>, int>> ans;
    for(auto &u : s1) {
        int x = u.first, y = u.second;
        if(union1(x, y)) {
            ans.push_back({{x, y}, 0});
            ct++;
        }
        if(ct == k) break;
    }
    if(ct < k) {
        cout << "no solution" << endl;
        return 0;
    }
    for(auto &u : s2) {
        int x = u.first, y = u.second;
        if(union2(x, y)) {
            ans.push_back({{x, y}, 1});
        }
    }
    for(auto &u : ans) {
        cout << u.first.first << ' ' << u.first.second << ' ' << u.second << endl;
    }
    return 0;
}