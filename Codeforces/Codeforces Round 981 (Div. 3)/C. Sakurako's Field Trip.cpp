// Problem: C. Sakurako's Field Trip
// Contest: Codeforces Round 981 (Div. 3)
// URL: https://codeforces.com/contest/2033/problem/C
// Start: Thu 24 Oct 2024 05:55:05 PM EEST
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(s) s.begin(), s.end()
void Fast();

void solve() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 1; i < n/2; i++) {
    int j = n-1-i;
    if(arr[i] == arr[i-1] || arr[j] == arr[j+1]){
      swap(arr[i], arr[j]);
    }
  }

  int ans = 0;
  for (int i = 1; i < n; i++) {
    if (arr[i] == arr[i - 1])
      ans++;
  }
  cout << ans << '\n';
}

int main() {
  Fast();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}

void Fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
