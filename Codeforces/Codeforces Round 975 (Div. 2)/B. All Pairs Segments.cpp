// Problem: B. All Pairs Segments
// Contest: Codeforces Round 975 (Div. 2)
// URL: https://codeforces.com/contest/2019/problem/B
// Start: Fri 27 Sep 2024 04:40:21 PM EEST
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(s) s.begin(), s.end()
void Fast();

void solve() {
  ll n, q;
  cin >> n >> q;
  ll arr[n], segs[n], ps[n];
  ps[0] = 0;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  map<ll, ll> mp;
  for (ll i = 0; i < n; i++) {
    segs[i] = i * (n - i) + (n - 1 - i);
    mp[segs[i]]++;
    if (i) {
      ps[i] = arr[i] - arr[i - 1] - 1;
      if (ps[i])
        mp[i * (n - i)] += ps[i];
    }
  }
  /* for (int i = 0; i < n; i++) {
     cout << segs[i] << ' ';
   }
   cout << '\n';
   for (int i = 0; i < n; i++) {
     cout << ps[i] << ' ';
   }
   cout << '\n'; */
  while (q--) {
    ll k;
    cin >> k;
    cout << mp[k] << ' ';
  }
  cout << '\n';
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
