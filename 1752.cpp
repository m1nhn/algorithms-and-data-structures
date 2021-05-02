/*
 * Author : Nguyen Le Minh
 * Group : N3251
 * Problem : 1752
 * Date : 18/4/2021
 */
#include <bits/stdc++.h>
#define l1 long long
#define maX 1001612
using namespace std;

vector<pair<l1,l1>> a1[maX];
vector<l1>a2[maX];
l1 a[maX], b[maX], ans[maX];

void dfs(l1 u, l1 v){
    l1 i;
    for (i = 0; i < a2[u].size(); i++){
        l1 p = a2[u][i];
        if(p == v) continue;
        a[p] = a[u] + 1;
        dfs(p,u);
    }
}

void anotherDFS(l1 u, l1 v, l1 di){
    b[di] = u;
    l1 i;
    while(!a1[u].empty()){
        l1 p = a1[u].back().first;
        if (p > di) break;
        l1 q = a1[u].back().second;
        ans[q] = b[di - p];
        a1[u].pop_back();
    }
    for (i = 0; i < a2[u].size(); i++){
        l1 p = a2[u][i];
        if (p == v) continue;
        anotherDFS(p,u,di + 1);
    }
}
void solve(){
    l1 n,q,i,u,v;
    cin >> n >> q;
    int up = 1;
    while(up--) {
        for (i = 1; i < n; i++) {
            cin >> u >> v;
            a2[u].push_back(v);
            a2[v].push_back(u);
        }

        for (i = 1; i <= q; i++) {
            l1 c, d;
            cin >> c >> d;
            a1[c].emplace_back(d, i);
        }

        for (i = 1; i <= n; i++) {
            sort(a1[i].begin(), a1[i].end());
            reverse(a1[i].begin(), a1[i].end());
        }

        l1 m = 0, e = 1, f = 1;
        dfs(1, -1);
        for (i = 1; i <= n; i++) {
            if (a[i] > m) {
                m = a[i];
                e = i;
            }
        }
        a[e] = m = 0;
        dfs(e, -1);
        for (i = 1; i <= n; i++) {
            if (a[i] > m) {
                m = a[i];
                f = i;
            }
        }

        anotherDFS(e, -1, 0);
        anotherDFS(f, -1, 0);

        for (i = 1; i <= q; i++) {
            cout << ans[i] << endl;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();
    return 0;
}

