/*
Problem Name : 1381. Design a Stack With Increment Operation
Author: Abdalrahman Shaban
Date: 30/09/2024 06:00:01
*/
#include <bits/stdc++.h>
using namespace std;

class CustomStack {
  int *arr;
  int n;
  int it;

public:
  CustomStack(int maxSize) {
    n = maxSize;
    arr = new int[n];
    it = 0;
  }

  void push(int x) {
    if (it == n)
      return;
    arr[it++] = x;
  }

  int pop() {
    if (it == 0)
      return -1;
    return arr[--it];
  }

  void increment(int k, int val) {
    for (int i = 0; i < min(k, it); i++) {
      arr[i] += val;
    }
  }
};
int main() { return 0; }
