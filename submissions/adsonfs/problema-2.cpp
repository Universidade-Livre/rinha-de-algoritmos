#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); i++)

int N, M, ans;
vector<int> adj[200];
int p[200], g[200], G[200], GG[200];

int f(int u) { return p[u] == u ? u : p[u] = f(p[u]); }

int bfs(int s) {
    int cnt = N;
    priority_queue<pair<int, int>> pq;
    pq.push({G[s], s});
    while(!pq.empty()) {
        if(cnt <= ans) return 0;
        int u = pq.top().second;
        int gg = pq.top().first;
        pq.pop();
        if(gg != G[u]) continue;
        int U = f(u);
        
        for(auto v : adj[u]) {
            int V = f(v);
            if(U == V) continue;
            cnt -= (g[u]++ == 1) + (g[v]++ == 1);
            G[u]--; G[v]--;
            p[V] = U;
            if(G[v]) pq.push({G[v], v});
        }
    }
    return cnt;
}

int main () {
    int u, v;
    scanf("%d%d", &N, &M);
    rep(i, 0, M) {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
        GG[u]++; GG[v]++;
    }

    rep(nz, 1, N+1) {
        rep(i, 1, 121) { p[i] = i; g[i] = 0; G[i] = GG[i]; }
        ans = max(ans, bfs(nz));
    }
    printf("%d\n", ans);
    return 0;
}
