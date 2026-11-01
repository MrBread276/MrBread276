#include <cmath>
#include <iostream>
#include <vector>
int main() {
  long long n;
  long long q;
  std::vector<double> midgeo;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    double a;
    std::cin >> a;
    if (i == 0) {
      midgeo.push_back(a);
    } else {
      double count = (1.0 / (i + 1)) / (1.0 / i);
      midgeo.push_back(std::pow(a, (1.0 / (i + 1))) * std::pow(midgeo[i - 1], count));
    }
  }
  std::cin >> q;
  for (int i = 0; i < q; i++) {
    int l;
    double count;
    int r;
    std::cin >> l >> r;
    if (l == 0) {
      std::cout << std::fixed << midgeo[r] << '\n';
    } else {
      int len = r - l + 1;
      count = std::pow(midgeo[l - 1], (1.0 / (r + 1)) / (1.0 / l));
      double ans = midgeo[r] / count;
      std::cout << std::fixed << std::pow(ans, (1.0 / len) / (1.0 / (r + 1)));
      std::cout << '\n';
    }
  }
  return 0;
}
