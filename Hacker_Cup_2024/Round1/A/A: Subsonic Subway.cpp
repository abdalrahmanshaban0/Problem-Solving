#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

typedef long long ll;
#define all(s) s.begin(), s.end()
void Fast();

bool chk(pair<ll, ll> &p1, pair<ll, ll> &p2) {
  return max(p1.first, p2.first) < min(p1.second, p2.second);
}

void solve() {
  ll n;
  cin >> n;
  vector<pair<double, double>> v(n);
  double mn = INT_MAX, mx = -1;
  for (double i = 1; i <= n; i++) {
    cin >> v[i-1].first >> v[i-1].second;
    double mxsp = v[i-1].first == 0 ? 1e18 : i / v[i-1].first;
    double mnsp = i / v[i-1].second;

    mx = max(mx, mnsp);
    mn = min(mn, mxsp);
  }
  if(mx > mn){
    cout << -1 << '\n';
  }
  else{
    cout << fixed << setprecision(12) << mx << '\n';
  }
}

int main() {
  Fast();
  int t;
  int it = 1;
  cin >> t;
  while (t--) {
    cout << "Case #" << it++ << ": ";
    solve();
  }

  return 0;
}

void Fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
