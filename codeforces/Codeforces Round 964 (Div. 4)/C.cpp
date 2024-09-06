/*
Problem Name : C
Author: Abdalrahman Shaban
Date: 04/09/2024 23:59:34
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(s) s.begin(), s.end()

void file();
void Fast();

void solve() {
  ll n, s, m;
  cin >> n >> s >> m;
  vector<pair<ll, ll>> v(n);
  for (auto &i : v)
    cin >> i.first >> i.second;
  sort(all(v));
  bool ok = (v[0].first >= s || (m - v[n - 1].second >= s));
  for (int i = 0; i + 1 < n; i++) {
    if (v[i + 1].first - v[i].second >= s) {
      ok = 1;
      break;
    }
  }
  if (ok) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

int main() {
  Fast();
  file();
  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}

void file() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif
}
void Fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
