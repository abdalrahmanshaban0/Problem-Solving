// Problem: Digit Queries
// Contest: CSES Problem Set
// URL: https://cses.fi/problemset/task/2431
// Start: Sat 25 Jan 2025 01:06:40 AM EET
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(s) s.begin(), s.end()
void Fast();

void solve() {
  int q;
  cin >> q;
  while (q--) {
    ll k;
    cin >> k;
    ll val = 9, d = 1;
    while (k - val * d >= 0) {
      k -= val * d;
      d++;
      val *= 10;
    }
    ll st = val / 9;
    ll numIdx = k / d - 1;
    int mod = k % d;
    ll num = st + numIdx + (mod ? 1 : 0);
    string s = to_string(num);
    int digitIdx = (mod ? mod : s.size()) - 1;
    cout << s[digitIdx] << '\n';
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
