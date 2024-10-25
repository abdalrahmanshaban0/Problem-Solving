// Problem: B. Sakurako and Water
// Contest: Codeforces Round 981 (Div. 3)
// URL: https://codeforces.com/contest/2033/problem/B
// Start: Thu 24 Oct 2024 05:38:08 PM EEST
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(s) s.begin(), s.end()
void Fast();

void solve() {
  int n;
  cin >> n;
  int arr[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int mn = 0;
    int k = 0;
    for (int j = i; j < n && k < n; j++, k++) {
      if (arr[k][j] < 0)
        mn = min(mn, arr[k][j]);
    }
    ans += mn;
  }
  for (int i = 1; i < n; i++) {
    int mn = 0;
    int k = 0;
    for (int j = i; j < n; j++, k++) {
      if (arr[j][k] < 0)
        mn = min(mn, arr[j][k]);
    }
    ans += mn;
  }
  cout << abs(ans) << '\n';
}

int main() {
  Fast();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}

void Fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
