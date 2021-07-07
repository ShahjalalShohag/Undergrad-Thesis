#include<bits/stdc++.h>
using namespace std;
#include "basics.h"

const int N = 3509;
bool f[N][N];
int w[N], mx[N], r[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input002.txt", "r", stdin);
  int n, m; cin >> n >> m;
  graph g(n);
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    f[u][v] = f[v][u] = 1;
  }
  double p = 0.02;
  auto core = kcore(n, m, g);
  // cout << core_resilience(50, 5, n, m, g, core) << '\n';
  vector<array<int, 2>> e;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (f[i][j]) continue;
      e.push_back({i, j});
    }
  }
  for (int u = 0; u < n; u++) {
    for (auto v: g[u]) {
      w[u] += core[u] > core[v];
      mx[u] = max(mx[u], core[v]);
    }
  }
  auto cost = [&](int u, int v) {
    // if (core[u] > core[v]) {
    //   return 1.0 * w[u] / core[u];
    // }
    // if (core[u] < core[v]) {
    //   return 1.0 * w[v] / core[v];
    // }
    if (core[u] + core[v] == 0) return 0.0;
    return 1.0 * (w[u] + w[v]) / (core[u] + core[v]); 
  };
  sort(e.begin(), e.end(), [&](array<int, 2> x, array<int, 2> y){
    return mx[x[0]] * mx[x[1]] + min(1.0 * core[x[0]] * core[x[1]], (w[x[0]] * w[x[1]]) - cost(x[0], x[1])) * abs(core[x[0]] - core[x[1]]) > mx[y[0]] * mx[y[1]] + min(1.0 * core[y[0]] * core[y[1]], (w[y[0]] * w[y[1]]) - cost(y[0], y[1])) * abs(core[y[0]] - core[y[1]]);
  });
  for (double p = 0.01; p <= 0.20; p += 0.01) {
    int tot = e.size();
    int cnt = 0, nxtm = m;
    graph ans = g;
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