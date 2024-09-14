/*
Problem Name : D
Author: Abdalrahman Shaban
Date: 14/09/2024 15:43:02
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(s) s.begin(), s.end()
void Fast();

void solve() {
  ll n;
  cin >> n;
  vector<pair<ll, ll>> v(n);
  set<pair<ll, ll>> st;
  ll sm = 0;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    v[i].first = x;
  }
  for (int i = 0; i < n; i++) {
    ll p;
    cin >> p;
    v[i].second = p;
    sm += p;
    st.insert({v[i].first, sm});
  }
  int q;
  cin >> q;
  while (q--) {
    ll l, r;
    cin >> l >> r;
    if(l > r) swap(l, r);
    auto itr = st.lower_bound({r, LONG_LONG_MIN});
    auto itl = st.lower_bound({l, LONG_LONG_MIN});
    if(itr == st.end())
      itr--;
    if(itr->first > r && itr == st.begin()){
      cout << 0 << '\n';
      continue;
    }
    if(itr->first > r) itr--;
    if (itl == st.begin()) {
      cout << itr->second << '\n';
    } else {
      itl--;
      cout << (itr->second) - (itl->second) << '\n';
    }
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
