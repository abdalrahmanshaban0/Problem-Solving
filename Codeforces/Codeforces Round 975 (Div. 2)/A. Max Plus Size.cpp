// Problem: A. Max Plus Size
// Contest: Codeforces Round 975 (Div. 2)
// URL: https://codeforces.com/contest/2019/problem/0
// Start: Fri 27 Sep 2024 04:36:24 PM EEST
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(s) s.begin(), s.end()
void Fast();

void solve() {
  int n;
  cin >> n;
  ll arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  ll ans = 0, mx1 = 0, cnt1 = 0;
  for (int i = 0; i < n; i += 2) {
    cnt1++;
    mx1 = max(mx1, arr[i]);
  }
  ans = mx1 + cnt1;
  mx1 = 0, cnt1 = 0;
  for (int i = 1; i < n; i += 2) {
    cnt1++;
    mx1 = max(mx1, arr[i]);
  }
  cout << max(ans, mx1+cnt1) << '\n';
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
