// Problem: A: Walk the Line
// Contest: Meta Hacker Cup 2024 Practice Round
// URL: https://www.facebook.com/codingcompetitions/hacker-cup/2024/practice-round/problems/A?source=facebook
// Start: Sat 05 Oct 2024 07:13:54 PM EEST
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(s) s.begin(), s.end()
void Fast();

void solve() {
  ll n, k; cin >> n >> k;
  ll arr[n];
  for(int i = 0 ;i < n; i++){
    cin >> arr[i];
  }
  if(n == 1){
    if(arr[0] <= k){
      cout << "YES\n";
    }
    else{
      cout << "NO\n";
    }
    return;
  }
  sort(arr, arr+n);
  if(2 * arr[0] * (n-2) + arr[0] <= k){
    cout << "YES\n";
  }
  else{
    cout << "NO\n";
  }
}

int main() {
  Fast();
  int t; cin >> t;
  int it = 1;
  while(t--){
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
