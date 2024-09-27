/*
Problem Name : 731. My Calendar II
Author: Abdalrahman Shaban
Date: 28/09/2024 00:19:34
*/

#include <bits/stdc++.h>
using namespace std;

class MyCalendarTwo {
  map<int, int> mp;

public:
  MyCalendarTwo() {}
  bool book(int start, int end) {
    mp[start]++;
    mp[end]--;
    int books = 0;
    for (auto &i : mp) {
      books += i.second;
      if (books == 3) {
        mp[start]--;
        mp[end]++;
        return false;
      }
    }
    return true;
  }
};
int main() { return 0; }
