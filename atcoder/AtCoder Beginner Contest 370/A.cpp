/*
Problem Name : A 
Author: Abdalrahman Shaban
Date: 07/09/2024 15:01:09
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(s) s.begin(), s.end()
void Fast();

void solve() {
  int l, r; cin >> l >> r;
  if((l && r) || (!l && !r)){
    cout << "Invalid";
  }
  else if(l){
    cout << "Yes";
  }
  else{
    cout <<"No";
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
