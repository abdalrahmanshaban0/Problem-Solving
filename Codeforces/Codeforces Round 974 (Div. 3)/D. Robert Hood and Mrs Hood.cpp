#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(s) s.begin(), s.end()
void Fast();

void solve() {
  int n, d, k;
  cin >> n >> d >> k;
  d = min(d, n);

  int st[n + 1], ed[n + 1];
  memset(st, 0, sizeof(st));
  memset(ed, 0, sizeof(ed));

  for (int i = 0; i < k; i++) {
    int l, r;
    cin >> l >> r;
    st[l]++;
    ed[r]++;
  }
  int sm = 0;
  for (int i = 1; i <= d; i++) {
    sm += st[i];
  }
  int mn = sm, mx = sm, ansmx = 1, ansmn = 1;
  for (int i = d + 1; i <= n; i++) {
    sm += st[i];
    sm -= ed[i - d];
    if (mx < sm) {
      mx = sm;
      ansmx = i-d+1;
    }
    if (mn > sm) {
      mn = sm;
      ansmn = i-d+1;
    }
  }
  cout << ansmx << " " << ansmn << '\n';
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
