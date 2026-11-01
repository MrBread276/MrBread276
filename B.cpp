#include <iostream>
#include <random>
#include <vector>
std::vector<int> arr;
size_t k;
std::random_device rd;
std::mt19937 gen(rd());
int QuickSort(size_t l, size_t r) {
  if (r == l) {
    return arr[l];
  }
  std::uniform_int_distribution<> distrib(l, r);
  int rdc = arr[distrib(gen)];
  size_t l1 = 0;
  size_t m = 0;
  for (size_t i = l; i <= r; i++) {
    if (arr[i] < rdc) {
      l1++;
    } else if (arr[i] == rdc) {
      m++;
    }
  }
  if (k < l + l1) {
    size_t i = l;
    size_t j = r;
    while (i < j) {
      while (i < j && arr[i] < rdc) {
        i++;
      }
      if (arr[i] >= rdc && arr[j] < rdc) {
        std::swap(arr[i], arr[j]);
        i++;
      }
      j--;
    }
    return QuickSort(l, l + l1 - 1);
  }
  if (k < l + l1 + m) {
    return rdc;
  }
  size_t i = l;
  size_t j = r;
  while (i < j) {
    while (i < j && arr[i] <= rdc) {
      i++;
    }
    if (arr[i] > rdc && arr[j] <= rdc) {
      std::swap(arr[i], arr[j]);
      i++;
    }
    j--;
  }
  return QuickSort(l + l1 + m, r);
}
int main() {
  const int cNeponimauZachemNazivatEtoConstantoY45 = 45;
  const int cNeponimauZachemNazivatEtoConstantoY123 = 123;
  const int cBch = 10004321;
  int n;
  long long a1;
  std::cin >> n >> k >> a1;
  if (n == 1) {
    std::cout << a1;
    return 0;
  }
  k--;
  arr.push_back(a1);
  std::cin >> a1;
  arr.push_back(a1);
  for (int i = 2; i < n; i++) {
    arr.push_back((arr[i - 1] * cNeponimauZachemNazivatEtoConstantoY123 +
                 arr[i - 2] * cNeponimauZachemNazivatEtoConstantoY45) %
                cBch);
  }
  std::cout << QuickSort(0, n - 1);
  return 0;
}
