#include<bits/stdc++.h>
using namespace std;
#include "basics.h"

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  graph g(n);
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  auto core = kcore(n, m, g);
  cout << core_resilience(50, 0, 5, n, m, g, core) << '\n';
  return 0;
}