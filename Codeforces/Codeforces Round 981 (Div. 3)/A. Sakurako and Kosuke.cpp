// Problem: A. Sakurako and Kosuke
// Contest: Codeforces Round 981 (Div. 3)
// URL: https://codeforces.com/contest/2033/problem/0
// Start: Thu 24 Oct 2024 05:35:26 PM EEST
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(s) s.begin(), s.end()
void Fast();

void solve() {
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    if(n&1){
      cout << "Kosuke\n";
    }
    else{
      cout << "Sakurako\n";
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
