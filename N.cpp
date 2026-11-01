#include <iostream>
#include <map>
#include <vector>
std::vector<std::vector<long long>> h;
std::map<long long, long long> hole;
std::map<long long, long long> endd;
bool Bett(std::vector<long long>& x, std::vector<long long>& y) {
  long long lx = x[1] - x[0];
  long long ly = y[1] - y[0];
  if (lx != ly) {
    return lx > ly;
  }
  return x[0] < y[0];
}
void SiftUp() {
  int u = h.size() - 1;
  while (u > 1 && Bett(h[u], h[u / 2])) {
    std::swap(h[u], h[u / 2]);
    u /= 2;
  }
}
void SiftDown() {
  int u = 1;
  while ((u * 2 < (int)h.size() && Bett(h[u * 2], h[u])) ||
         (u * 2 + 1 < (int)h.size() && Bett(h[u * 2 + 1], h[u]))) {
    if (Bett(h[u * 2], h[u]) &&
        (u * 2 + 1 >= (int)h.size() || !Bett(h[u * 2 + 1], h[u * 2]))) {
      std::swap(h[u], h[u * 2]);
      u *= 2;
    } else {
      std::swap(h[u], h[u * 2 + 1]);
      u = u * 2 + 1;
    }
  }
}
void Pop() {
  std::swap(h[1], h[h.size() - 1]);
  h.pop_back();
  if (h.size() > 1) {
    SiftDown();
  }
}
void Add(long long l, long long r) {
  hole[l] = r;
  endd[r] = l;
  h.push_back({l, r});
  SiftUp();
}
bool Dead() {
  if (!hole.contains(h[1][0])) {
    return false;
  }
  return hole[h[1][0]] == h[1][1];
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  long long n;
  int q;
  std::cin >> n >> q;
  h.push_back({0, 0});
  Add(1, n);
  std::vector<long long> start(q + 1, 0);
  std::vector<long long> sizee(q + 1, 0);
  std::vector<bool> ok(q + 1, false);
  std::vector<bool> free(q + 1, false);
  for (int i = 1; i <= q; i++) {
    long long k;
    std::cin >> k;
    if (k > 0) {
      while (h.size() > 1 && !Dead()) {
        Pop();
      }
      if (h.size() == 1 || h[1][1] - h[1][0] + 1 < k) {
        std::cout << -1 << '\n';
      } else {
        long long l = h[1][0];
        long long r = h[1][1];
        Pop();
        hole.erase(l);
        endd.erase(r);
        ok[i] = true;
        start[i] = l;
        sizee[i] = k;
        std::cout << l << '\n';
        if (l + k <= r) {
          Add(l + k, r);
        }
      }
    } else {
      int j = -k;
      if (!ok[j] || free[j]) {
        continue;
      }
      free[j] = true;
      long long l = start[j];
      long long r = start[j] + sizee[j] - 1;
      if (hole.contains(r + 1)) {
        long long nr = hole[r + 1];
        hole.erase(r + 1);
        endd.erase(nr);
        r = nr;
      }
      if (endd.contains(l - 1)) {
        long long nl = endd[l - 1];
        hole.erase(nl);
        endd.erase(l - 1);
        l = nl;
      }
      Add(l, r);
    }
  }
  return 0;
}
