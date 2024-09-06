/*
Problem Name : B
Author: Abdalrahman Shaban
Date: 04/09/2024 23:04:45
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(s) s.begin(), s.end()

void file();
void Fast();

int foo(int a, int b) {
  if (a > b)
    return 1;
  if (a < b)
    return -1;
  return 0;
}

void solve() {
  int a1, a2, b1, b2;
  cin >> a1 >> a2 >> b1 >> b2;
  int ans = 0;
  if (foo(a1, b1) + foo(a2, b2) > 0)
    ans++;
  if (foo(a1, b2) + foo(a2, b1) > 0)
    ans++;
  if (foo(a2, b1) + foo(a1, b2) > 0)
    ans++;
  if (foo(a2, b2) + foo(a1, b1) > 0)
    ans++;
  cout << ans << '\n';
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
