/*
Problem Name : G1
Author: Abdalrahman Shaban
Date: 05/09/2024 01:35:05
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(s) s.begin(), s.end()

void Fast();

void solve() {
  int l = 1, r = 1000, cnt = 10;
  int ans = -1;
  while (l <= r && cnt--) {
    int md = (l + r) / 2;
    cout << "? " << l << ' ' << md << endl;
    int val = -1;
    cin >> val;
    if (val != l * md) {
      r = md;
    } else {
      l = md + 1;
      ans = l;
    }
  }
  cout << "! " << ans << endl;
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
