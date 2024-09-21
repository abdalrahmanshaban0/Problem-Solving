/*
Problem Name : Range Xor Queries
Author: Abdalrahman Shaban
Date: 17/09/2024 01:48:17
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(s) s.begin(), s.end()
void Fast();

void solve() {
  int n, q;
  cin >> n >> q;
  ll arr[n], prf[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (i == 0)
      prf[i] = arr[i];
    else
      prf[i] = (prf[i - 1] ^ arr[i]);
  }
  while(q--){
    int l, r; cin >> l >> r;
    --l, --r;
    if(l){
      cout << (prf[r]^prf[l-1]) << '\n';
    }
    else{
      cout << (prf[r]) << '\n';
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
