/*
Problem Name : B 
Author: Abdalrahman Shaban
Date: 07/09/2024 15:05:04
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(s) s.begin(), s.end()
void Fast();

void solve() {
  int n; cin >> n;
  vector<vector<int>> v(n);
  for(int i = 0 ;i < n; i++){
    for(int j = 0; j <= i; j++){
      int val; cin >> val;
      v[i].push_back(val);
    }
  }
  int el = 1;
  for(int i = 1; i <= n; i++){
    if(el >= i){
      el = v[el-1][i-1];
    }
    else{
      el = v[i-1][el-1];
    }
  }
  cout << el ;
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
