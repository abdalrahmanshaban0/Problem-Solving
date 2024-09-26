/*
Problem Name : 729. My Calendar I
Author: Abdalrahman Shaban
Date: 26/09/2024 22:13:18
*/
#include <bits/stdc++.h>
using namespace std;

class MyCalendar {
  map<pair<int, int>, int> mp;

public:
  MyCalendar() {}

  bool book(int start, int end) {
    if (mp.empty()) {
      mp[{start, end}] = 1;
      return true;
    }

    auto it = mp.lower_bound({start, end});
    if (it != mp.end()) {
      if ((it->first.first >= start && it->first.first < end) ||
          (it->first.second > start && it->first.second < end))
        return false;
    }
    it--;

    if ((start >= it->first.first && start < it->first.second) ||
        (end > it->first.first && end < it->first.second))
      return false;

    mp[{start, end}] = 1;

    return true;
  }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

int main() { return 0; }
