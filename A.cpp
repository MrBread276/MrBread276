#include <iostream>
#include <vector>
std::vector<std::pair<int, int>> a;
std::vector<std::pair<int, int>> MerdgeSort(int l, int r) {
  if (r - l == 0) {
    return {a[l]};
  }
  int m = (r + l) / 2;
  std::vector<std::pair<int, int>> ans;
  std::vector<std::pair<int, int>> l1 = MerdgeSort(l, m);
  std::vector<std::pair<int, int>> r1 = MerdgeSort(m + 1, r);
  size_t ul = 0;
  size_t ur = 0;
  while (ul < l1.size() || ur < r1.size()) {
    if (ul >= l1.size()) {
      ans.push_back(r1[ur]);
      ur++;
    } else if (ur >= r1.size()) {
      ans.push_back(l1[ul]);
      ul++;
    } else if (l1[ul] < r1[ur]) {
      ans.push_back(l1[ul]);
      ul++;
    } else {
      ans.push_back(r1[ur]);
      ur++;
    }
  }
  return ans;
}
int main() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> ans;
  for (int i = 0; i < n; i++) {
    int x;
    int y;
    std::cin >> x >> y;
    a.push_back({x, y});
  }
  a = MerdgeSort(0, n - 1);
  int i = 0;
  int l = -1;
  int r = 0;
  while (i < n) {
    if (l == -1) {
      l = a[i].first;
    } else if (r < a[i].first) {
      ans.push_back({l, r});
      l = a[i].first;
    }
    r = std::max(r, a[i].second);
    i++;
  }
  ans.push_back({l, r});
  std::cout << ans.size() << '\n';
  for (size_t i = 0; i < ans.size(); i++) {
    std::cout << ans[i].first << " " << ans[i].second << '\n';
  }
  return 0;
}
