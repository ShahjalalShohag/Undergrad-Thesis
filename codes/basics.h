using graph = vector<vector<int>>;

// print a graph
void print(int n, graph &g) {
  cout << "graph:\n";
  for (int i = 0; i < n; i++) {
    for (auto j: g[i]) {
      if (i < j) {
        cout << i << ' ' << j << '\n';
      }
    }
  }
  cout << "-----\n\n";
}
// returns core numbers of a simple 0 indexed graph g
vector<int> kcore(int n, int m, graph &g) {
  vector<int> deg(n, 0), core(n, 0);
  for (int u = 0; u < n; u++) {
    deg[u] = g[u].size();
  }
  set<array<int, 2>> se;
  int mx = 0;
  for (int i = 0; i < n; i++) {
    se.insert({deg[i], i});
    mx = max(mx, deg[i]);
  }
  for (int i = 0; i <= mx; i++) {
    while (!se.empty()) {
      auto [d, u] = *se.begin();
      if (d > i) break;
      core[u] = i;
      se.erase(se.begin());
      for (auto v: g[u]) {
        if (deg[v] == 0) continue;
        se.erase({deg[v], v});
        deg[v]--;
        se.insert({deg[v], v});
      }
    }
  }
  return core;
}
mt19937 rnd(69); // should change the seed by time
// delete p% edges randomly and store the modified graph in gnxt
void edge_deletion(int n, int m, graph &g, double p, int &nnxt, int &mnxt, graph &gnxt) {
  vector<array<int, 2>> edges;
  for (int u = 0; u < n; u++) {
    for (auto v: g[u]) {
      if (u < v) {
        edges.push_back({u, v});
      }
    }
  }
  assert(edges.size() == m);
  shuffle(edges.begin(), edges.end(), rnd);
  while (!edges.empty()) {
    int k = m - (int)edges.size() + 1;
    if (k * 100 > p * m) break;
    edges.pop_back();
  }
  nnxt = n;
  mnxt = edges.size();
  gnxt.resize(n);
  for (auto [u, v]: edges) {
    gnxt[u].push_back(v);
    gnxt[v].push_back(u);
  }
  return;
}
// https://web.archive.org/web/20181008171919/https://docs.scipy.org/doc/scipy/reference/generated/scipy.stats.kendalltau.html
double kendall_tau(vector<array<int, 2>> a) {
  int n = a.size(), p = 0, q = 0, u = 0, t = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] == a[j]) continue;
      if (a[i][0] == a[j][0]) ++t;
      else if (a[i][1] == a[j][1]) ++u;
      else if (a[i][0] > a[j][0] and a[i][1] > a[j][1]) ++p;
      else if (a[i][0] < a[j][0] and a[i][1] < a[j][1]) ++p;
      else ++q;
    }
  }
  if ((p + q + t) == 0 or (p + q + u) == 0) return 0.0;
  double ans = 1.0 * (p - q) / sqrt(1.0L * (p + q + t) * (p + q + u));
  return ans;
}
// returns (r, p) core resilience of g, core numbers are given
double core_resilience(double r, double p, int n, int m, graph &g, vector<int> &core) {
  vector<int> nodes(n);
  iota(nodes.begin(), nodes.end(), 0);
  sort(nodes.begin(), nodes.end(), [&](int u, int v) {
    return core[u] > core[v];
  });
  int k = 0;
  vector<int> v; // top r% nodes
  for (auto u: nodes) {
    k++;
    if (k * 100 > r * n) break;
    v.push_back(u);
  }
  k = v.size();
  if (k == 0) {
    return 1.0;
  }
  vector<int> prv(k);
  for (int i = 0; i < k; i++) {
    prv[i] = core[v[i]];
  }
  int nnxt, mnxt; graph gnxt;
  edge_deletion(n, m, g, p, nnxt, mnxt, gnxt);
  vector<int> nxtcore = kcore(nnxt, mnxt, gnxt);

  vector<int> nxt(k);
  for (int i = 0; i < k; i++) {
    nxt[i] = nxtcore[v[i]];
  }

  vector<array<int, 2>> ans;
  for (int i = 0; i < k; i++) {
    ans.push_back({prv[i], nxt[i]});
  }
  // cout << ans.size() << '\n';
  // for (auto [i, j]: ans) {
  //   cout << i << ' ' << j << '\n';
  // }
  return kendall_tau(ans);
}
// returns (r, pl, pr) core resilience of g, core numbers are given
double core_resilience(double r, int pl, int pr, int n, int m, graph &g, vector<int> &core) {
  double ans = 0;
  for (int i = pl; i <= pr; i++) {
    ans += core_resilience(r, i, n, m, g, core);
  }
  ans /= pr - pl + 1;
  return ans;
}