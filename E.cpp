#include <algorithm>
#include <iostream>
#include <vector>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int n;
  std::cin >> n;
  std::vector<int> a;
  std::vector<int> b;
  for (int i = 0; i < n; i++) {
    int p;
    std::cin >> p;
    a.push_back(p);
  }
  for (int i = 0; i < n; i++) {
    int p;
    std::cin >> p;
    b.push_back(p);
  }
  int q;
  std::cin >> q;
  for (int i = 0; i < q; i++) {
    int x;
    std::cin >> x;
    int l = 0;
    int r = n - 1;
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (a[m] + x < b[m]) {
        l = m;
      } else {
        r = m;
      }
    }
    if (std::max(a[l] + x, b[l]) < std::max(a[r] + x, b[r])) {
      std::cout << l + 1 << '\n';
    } else {
      std::cout << r + 1 << '\n';
    }
  }
  return 0;
}
