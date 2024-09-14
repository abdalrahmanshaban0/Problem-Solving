/*
Problem Name : B
Author: Abdalrahman Shaban
Date: 14/09/2024 15:15:58
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(s) s.begin(), s.end()
void Fast();

void solve() {
  int f, b;
  cin >> f >> b;
  vector<map<int, int>> v(f);
  while (b--) {
    int a;
    char c;
    cin >> a >> c;
    if (c == 'M') {
      if (v[a - 1][c] == 0) {
        cout << "Yes\n";
      } else {
        cout << "No\n";
      }
      v[a - 1][c]++;
    }
    else{
      cout << "No\n";
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
