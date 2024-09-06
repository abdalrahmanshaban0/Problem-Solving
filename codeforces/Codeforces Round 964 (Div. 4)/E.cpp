/*
Problem Name : E
Author: Abdalrahman Shaban
Date: 05/09/2024 00:34:01
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(s) s.begin(), s.end()

void file();
void Fast();

const int N = 2e5 + 5;
int logs3[N];

int log3(int val) {
  int cnt = 0;
  while (val) {
    val /= 3;
    cnt++;
  }
  return cnt;
}

void solve() {
  int l, r;
  cin >> l >> r;
  int ans = 2 * logs3[l];
  for (int i = l + 1; i <= r; i++) {
    ans += logs3[i];
  }
  cout << ans << "\n";
}

int main() {
  Fast();
  file();
  int t;

  for (int i = 1; i < N; i++) {
    logs3[i] = log3(i);
  }

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
