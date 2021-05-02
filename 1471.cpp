/*
 * Author : Nguyen Le Minh
 * Group : N3251
 * Date : 9/4/2021
 * Problem : 1471
 */

#include <bits/stdc++.h>

using namespace std;

const int MAXLOG = 16;
vector <vector<pair<int,int>>> adj;
vector <vector< int > > dp;
vector < int > dist;
vector < int > h;
int n,q;

void dfs(int u,int par){
    dp[0][u] = par;
    for(auto [v,w] : adj[u]){
        if(v != par){
            h[v] = h[u] + 1;
            dist[v] = dist[u] + w;
            dfs(v,u);
        }
    }
}

int getLca(int u,int v){
    if(h[u] < h[v]){
        swap(u,v);
    }
    for(int j = MAXLOG;~j;--j){
        if(h[dp[j][u]] >= h[v]){
            u = dp[j][u];
        }
    }
    if(u == v){
        return u;
    }
    for(int j = MAXLOG;j > -1;--j){
        if(dp[j][u] != dp[j][v]){
            u = dp[j][u];
            v = dp[j][v];
        }
    }
    return dp[0][u];
}

int getDist(int u,int v){
    return dist[u] + dist[v] - 2 * dist[getLca(u,v)];
}

void solve(){
    cin>>n;
    adj.resize(n + 2,vector < pair < int,int > > ());
    for(int i = 1;i < n;++i){
        int u,v,w; cin>>u>>v>>w;
        adj[u].emplace_back(make_pair(v,w));
        adj[v].emplace_back(make_pair(u,w));
    }
    dist.resize(n + 2,0);
    h.resize(n + 2,0);
    dp.resize(MAXLOG + 2,vector < int > (n + 2,0));
    dfs(0,0);
    for(int j = 1;j <= MAXLOG;++j){
        for(int i = 0;i < n;++i){
            dp[j][i] = dp[j - 1][dp[j - 1][i]];
        }
    }
    cin>>q;
    while(q--){
        int u,v; cin>>u>>v;
        cout<<getDist(u,v)<<'\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
