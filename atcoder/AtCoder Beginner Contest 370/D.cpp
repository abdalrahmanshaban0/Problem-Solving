/*
Problem Name : D
Author: Abdalrahman Shaban
Date: 07/09/2024 15:35:04
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(s) s.begin(), s.end()
void Fast();

void solve() {
  int n, m;
  cin >> n >> m;
  vector<set<int>> r(n + 1), c(m + 1);
  vector<vector<bool>> vis(n + 1, vector<bool>(m + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      r[i].insert(j);
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      c[i].insert(j);
    }
  }

  int q;
  cin >> q;
  int cnt = 0;
  while (q--) {
    int x, y;
    cin >> x >> y;
    if (!vis[x][y]) {
      vis[x][y] = 1;
      r[x].erase(y);
      c[y].erase(x);
      cnt++;
    } else {
      auto rr = r[x].lower_bound(y);
      if (rr != r[x].end()) {
        vis[x][*rr] = 1;
        r[x].erase(rr);
        c[*rr].erase(x);
        cnt++;
      }
      rr = r[x].lower_bound(y);
      if (rr != r[x].begin()) {
        rr--;
        vis[x][*rr] = 1;
        r[x].erase(rr);
        c[*rr].erase(x);
        cnt++;
      }

      auto cr = c[y].lower_bound(x);
      if (cr != c[y].end()) {
        vis[*cr][y] = 1;
        c[y].erase(cr);
        r[*cr].erase(y);
        cnt++;
      }
      cr = c[y].lower_bound(x);
      if (cr != c[y].begin()) {
        cr--;
        vis[*cr][y] = 1;
        c[y].erase(cr);
        r[*cr].erase(y);
        cnt++;
      }
    }
  }

  cout << n * m - cnt;
}

int main() {
  Fast();
  solve();

  return 0;
}

void Fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
