/*
Problem Name : D
Author: Abdalrahman Shaban
Date: 05/09/2024 00:14:33
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(s) s.begin(), s.end()

void file();
void Fast();

void solve() {
  string a, b;
  cin >> a >> b;
  int j = 0;
  for (int i = 0; i < a.size() && j < b.size(); i++) {
    if (a[i] == b[j] || a[i] == '?') {
      a[i] = b[j++];
    }
  }
  if (j < b.size()) {
    cout << "NO\n";
  } else {
    for (int i = 0; i < a.size(); i++) {
      if (a[i] == '?')
        a[i] = 'a';
    }
    cout << "YES\n" << a << '\n';
  }
}

int main() {
  Fast();
  file();
  int t;
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
