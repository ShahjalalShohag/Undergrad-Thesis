 #include<bits/stdc++.h>
using namespace std;
#include "basics.h"

const int N = 3509;
bool f[N][N]; int deg[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  graph g(n);
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    deg[u]++; deg[v]++;
    f[u][v] = f[v][u] = 1;
  }
  double p = 0.02;
  auto core = kcore(n, m, g);
  vector<array<int, 2>> e;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (f[i][j]) continue;
      e.push_back({i, j});
    }
  }
  sort(e.begin(), e.end(), [&](array<int, 2> x, array<int, 2> y){
    return deg[x[0]] + deg[x[1]] > deg[y[0]] + deg[y[1]];
  });
  // cout << core_resilience(50, 5, n, m, g, core) << '\n';
  for (double p = 0.01; p <= 0.20; p += 0.01) {
    graph ans = g;
    int tot = e.size();
    int cnt = 0, nxtm = m;
    for (auto [u, v]: e) {
      cnt++;
      if (cnt * 100 > tot * p) break;
      ans[u].push_back(v);
      ans[v].push_back(u);
      ++nxtm;
    }
    // cout << cnt << '\n';
    core = kcore(n, nxtm, ans);
    cout << core_resilience(50, 0, 5, n, nxtm, ans, core) << '\n';
  }
  return 0;
}