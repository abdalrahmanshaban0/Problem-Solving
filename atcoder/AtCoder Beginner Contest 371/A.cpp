/*
Problem Name : A
Author: Abdalrahman Shaban
Date: 14/09/2024 15:00:41
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(s) s.begin(), s.end()
void Fast();

void solve() {
  char ab, ac, bc;
  cin >> ab >> ac >> bc;

  if (ab == '<' && ac == '<' && bc == '<') {
    cout << 'B';
  }
  if (ab == '<' && ac == '<' && bc == '>') {
    cout << 'C';
  }
  if (ab == '<' && ac == '>' && bc == '<') {
    cout << 'A';
  }
  if (ab == '<' && ac == '>' && bc == '>') {
    cout << 'A';
  }

  if (ab == '>' && ac == '<' && bc == '<') {
    cout << 'A';
  }
  if (ab == '>' && ac == '<' && bc == '>') {
    cout << 'B';
  }
  if (ab == '>' && ac == '>' && bc == '<') {
    cout << "C";
  }
  if (ab == '>' && ac == '>' && bc == '>') {
    cout << 'B';
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
