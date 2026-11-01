#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <vector>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::queue<int> l;
  std::deque<int> r;
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    char q;
    std::cin >> q;
    if (q == '-') {
      std::cout << l.front() << '\n';
      l.pop();
      if (l.size() < r.size()) {
        l.push(r.front());
        r.pop_front();
      }
    } else if (q == '+') {
      int x;
      std::cin >> x;
      r.push_back(x);
      if (l.size() < r.size()) {
        l.push(r.front());
        r.pop_front();
      }
    } else {
      int x;
      std::cin >> x;
      if (l.size() > r.size()) {
        r.push_front(x);
      } else {
        l.push(x);
      }
    }
  }
  return 0;
}
