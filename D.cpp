#include <cstdint>
#include <iostream>
#include <vector>
int main() {
  const int c8 = 8;
  const int c255 = 255;
  const int c256 = 256;
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int n;
  std::cin >> n;
  std::vector<uint64_t> arr;
  std::vector<uint64_t> buf(n);
  for (int i = 0; i < n; i++) {
    uint64_t x;
    std::cin >> x;
    arr.push_back(x);
  }
  for (int i = 0; i < c8; i++) {
    int shift = c8 * i;
    size_t bucklen[c256] = {0};
    for (int i = 0; i < n; i++) {
      bucklen[(arr[i] >> shift) & c255]++;
    }
    size_t start[c256];
    start[0] = 0;
    for (int i = 1; i < c256; i++) {
      start[i] = start[i - 1] + bucklen[i - 1];
    }
    for (int i = 0; i < n; i++) {
      buf[start[(arr[i] >> shift) & c255]++] = arr[i];
    }
    arr.swap(buf);
  }
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
}
