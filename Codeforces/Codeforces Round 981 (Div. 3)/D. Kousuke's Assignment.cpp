// Problem: D. Kousuke's Assignment
// Contest: Codeforces Round 981 (Div. 3)
// URL: https://codeforces.com/contest/2033/problem/D
// Start: Thu 24 Oct 2024 06:21:00 PM EEST
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
  set<ll> st;

  ll sm = 0;

  st.insert(sm);
  ll ans = 0;

  for (int i = 0; i < n; i++) {
    sm += arr[i];
    if (st.count(sm)) {
      ans++;
      sm = 0;
      st.clear();
      st.insert(0);
    }
    st.insert(sm);
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
