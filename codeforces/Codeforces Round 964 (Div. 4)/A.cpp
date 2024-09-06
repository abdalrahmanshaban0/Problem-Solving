/*
Problem Name : A
Author: Abdalrahman Shaban
Date: 04/09/2024 23:00:31
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(s) s.begin(), s.end()

void file();
void Fast();

void solve() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int sm = 0;
    for (auto &i : s) {
      sm += i - '0';
    }
    cout << sm << '\n';
  }
}

int main() {
  Fast();
  file();
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
