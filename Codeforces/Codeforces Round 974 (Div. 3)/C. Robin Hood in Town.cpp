#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
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
  ll l = 0, r = 1e17;
  ll ans = -1;
  while (l <= r) {
    ll x = (l + r) / 2;
    ll *ptr = max_element(arr, arr + n);
    ll mx = *ptr;
    double avg = accumulate(arr, arr + n, x) / (double)n;

    ll cnt = 0;
    ll temp = *ptr;
    *ptr = *ptr + x;
    for (int i = 0; i < n; i++) {
      if (arr[i] < avg / 2.0) {
        cnt++;
      }
    }
    *ptr = temp;
    if (cnt > n / 2) {
      ans = x;
      r = x - 1;
    } else {
      l = x + 1;
    }
  }
  cout << ans << '\n';
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
