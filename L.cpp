#include <iostream>
#include <string>
#include <utility>
#include <vector>
int main() {
  std::string s;
  std::string t;
  std::cin >> s >> t;
  t += '1';
  std::vector<std::pair<bool, char>> a;
  std::vector<int> idx;
  for (size_t i = 0; i < s.size(); i++) {
    a.push_back({1, s[i]});
    int p;
    std::cin >> p;
    idx.push_back(p);
  }
  int l = 0;
  int r = s.size() - 1;
  while (r - l > 1) {
    int m = (l + r) / 2;
    for (int i = 0; i <= m; i++) {
      a[idx[i] - 1].first = false;
    }
    size_t u = 0;
    for (size_t i = 0; i < s.size(); i++) {
      if (a[i].first && t[u] == a[i].second) {
        u++;
      }
      a[i].first = true;
    }
    if (u == t.size() - 1) {
      l = m;
    } else {
      r = m;
    }
  }
  for (int i = 0; i <= r; i++) {
    a[idx[i] - 1].first = false;
  }
  size_t u = 0;
  for (size_t i = 0; i < s.size(); i++) {
    if (a[i].first && t[u] == a[i].second) {
      u++;
    }
    a[i].first = true;
  }
  if (u == t.size() - 1) {
    std::cout << r + 1;
  } else {
    for (int i = 0; i <= l; i++) {
      a[idx[i] - 1].first = false;
    }
    u = 0;
    for (size_t i = 0; i < s.size(); i++) {
      if (a[i].first && t[u] == a[i].second) {
        u++;
      }
    }
    if (u == t.size() - 1) {
      std::cout << l + 1;
    } else {
      std::cout << 0;
    }
  }
  return 0;
}
