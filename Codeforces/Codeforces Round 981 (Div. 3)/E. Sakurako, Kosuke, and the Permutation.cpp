// Problem: E. Sakurako, Kosuke, and the Permutation
// Contest: Codeforces Round 981 (Div. 3)
// URL: https://codeforces.com/contest/2033/problem/E
// Start: Thu 24 Oct 2024 07:21:49 PM EEST
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(s) s.begin(), s.end()
void Fast();

int rec(int n, vector<int> &p) {
  vector<bool> vis(n + 1, false);
  int ret = 0;

  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      int cl = 0;
      int cur = i;
      while (!vis[cur]) {
        vis[cur] = true;
        cur = p[cur - 1];
        cl++;
      }
      if (cl > 1) {
        ret += (cl-1)/2;
      }
    }
  }
  return ret;
}
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &i : v)
    cin >> i;
  cout << rec(n, v) << '\n';
}

int main() {
  Fast();
  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}

void Fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
