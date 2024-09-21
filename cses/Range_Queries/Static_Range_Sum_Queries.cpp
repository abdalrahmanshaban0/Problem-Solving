/*
Problem Name : Static Range Sum Queries
Author: Abdalrahman Shaban
Date: 06/09/2024 22:25:14
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(s) s.begin(), s.end()
void Fast();

void solve() {
  int n, q;
  cin >> n >> q;
  ll arr[n], prf[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (i == 0)
      prf[i] = arr[i];
    else
      prf[i] = prf[i - 1] + arr[i];
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    cout << prf[r] - (l ? prf[l - 1] : 0) << '\n';
  }
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
