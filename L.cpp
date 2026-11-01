#include <iostream>
#include <vector>
void SiftUp(std::vector<int>& a, bool ind) {
  int u = a.size() - 1;
  while (u > 1 && ((!ind && a[u / 2] < a[u]) || (ind && a[u / 2] > a[u]))) {
    std::swap(a[u], a[u / 2]);
    u /= 2;
  }
}
void SiftDown(std::vector<int>& a, bool ind) {
  int u = 1;
  while ((u * 2 < (int)a.size() &&
          ((!ind && a[u * 2] < a[u]) || (ind && a[u * 2] > a[u]))) ||
         (u * 2 + 1 < (int)a.size() &&
          ((!ind && a[u * 2 + 1] < a[u]) || (ind && a[u * 2 + 1] > a[u])))) {
    if ((!ind && (a[u * 2] < a[u]) &&
         (u * 2 + 1 >= (int)a.size() || a[u * 2 + 1] >= a[u * 2])) ||
        (ind && (a[u * 2] > a[u]) &&
         (u * 2 + 1 >= (int)a.size() || a[u * 2 + 1] <= a[u * 2]))) {
      std::swap(a[u], a[u * 2]);
      u *= 2;
    } else {
      std::swap(a[u], a[u * 2 + 1]);
      u = u * 2 + 1;
    }
  }
}
void Get(std::vector<int>& a, std::vector<int>& b, bool ind) {
  while (a.size() > 1 && b.size() > 1 && a[1] == b[1]) {
    std::swap(a[1], a[a.size() - 1]);
    a.pop_back();
    SiftDown(a, ind);
    std::swap(b[1], b[b.size() - 1]);
    b.pop_back();
    SiftDown(b, ind);
  }
  if (a.size() == 1) {
    std::cout << "error" << '\n';
  } else {
    std::cout << a[1] << '\n';
  }
}
void Extr(std::vector<int>& a, std::vector<int>& delb, std::vector<int>& dela,
          bool ind) {
  Get(a, delb, ind);
  if (a.size() > 1) {
    dela.push_back(a[1]);
    std::swap(a[1], a[a.size() - 1]);
    a.pop_back();
    SiftDown(a, ind);
    SiftUp(dela, ind);
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::vector<int> a = {0};
  std::vector<int> dela = {0};
  std::vector<int> b = {0};
  std::vector<int> delb = {0};
  int q;
  std::cin >> q;
  for (int i = 0; i < q; i++) {
    int k;
    std::cin >> k;
    if (k == 6) {
      std::cout << "ok" << '\n';
      a.resize(1);
      dela.resize(1);
      b.resize(1);
      delb.resize(1);
    } else if (k == 5) {
      std::cout << a.size() - delb.size() << '\n';
    } else if (k == 0) {
      std::cout << "ok" << '\n';
      int p;
      std::cin >> p;
      a.push_back(p);
      b.push_back(p);
      SiftUp(a, true);
      SiftUp(b, false);
    } else if (k == 2) {
      Get(a, delb, false);
    } else if (k == 4) {
      Get(b, dela, true);
    } else if (k == 3) {
      Extr(b, dela, delb, true);
    } else {
      Extr(a, delb, dela, false);
    }
  }
  return 0;
}
