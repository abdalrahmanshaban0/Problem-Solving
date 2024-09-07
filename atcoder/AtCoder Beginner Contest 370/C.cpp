/*
Problem Name : C
Author: Abdalrahman Shaban
Date: 07/09/2024 15:16:36
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(s) s.begin(), s.end()
void Fast();

void solve() {
  string s, t;
  cin >> s >> t;
  int n = s.size();
  vector<string> ans;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (s[i] != t[i] && s[i] > t[i]) {
        s[i] = t[i];
        ans.push_back(s);
        break;
      }
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] != t[i]) {
      s[i] = t[i];
      ans.push_back(s);
    }
  }
  cout << ans.size() << '\n';
  for (auto &i : ans) {
    cout << i << '\n';
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
