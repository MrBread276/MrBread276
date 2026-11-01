#include <iostream>
#include <vector>
struct Point {
  long long val;
  int par = 0;
  int kid = 0;
  int sib = 0;
  int idx = 0;
  int rang = 0;
  int nheap = 0;
};
const int cH21 = 21;
std::vector<std::vector<int>> heaptop;
std::vector<int> mn;
std::vector<int> pos;
std::vector<Point> heap;
bool Less(int s, int t) {
  if (heap[s].val != heap[t].val) {
    return heap[s].val < heap[t].val;
  }
  return heap[s].idx < heap[t].idx;
}
void Upd(int a) {
  mn[a] = 0;
  for (int i = 0; i < cH21; i++) {
    int x = heaptop[a][i];
    if (x != 0) {
      heap[x].nheap = a;
      if (mn[a] == 0 || Less(x, mn[a])) {
        mn[a] = x;
      }
    }
  }
}
void Merge(int a, int b) {
  if (a == b) {
    return;
  }
  int ch = 0;
  for (int i = 0; i < cH21; i++) {
    int t[3];
    int c = 0;
    if (heaptop[a][i] != 0) {
      t[c] = heaptop[a][i];
      c++;
    }
    if (heaptop[b][i] != 0) {
      t[c] = heaptop[b][i];
      c++;
    }
    if (ch != 0) {
      t[c] = ch;
      c++;
    }
    heaptop[a][i] = 0;
    heaptop[b][i] = 0;
    ch = 0;
    if (c == 1 || c == 3) {
      c--;
      heaptop[b][i] = t[c];
    }
    if (c == 2) {
      int t0 = t[0];
      int t1 = t[1];
      if (Less(t1, t0)) {
        int t = t0;
        t0 = t1;
        t1 = t;
      }
      heap[t1].par = t0;
      heap[t1].sib = heap[t0].kid;
      heap[t0].kid = t1;
      heap[t0].rang++;
      ch = t0;
    }
  }
  mn[a] = 0;
  Upd(b);
}
int SiftUp(int s, bool ind) {
  while (heap[s].par != 0 && (ind || Less(s, heap[s].par))) {
    int p = heap[s].par;
    long long tv = heap[s].val;
    heap[s].val = heap[p].val;
    heap[p].val = tv;
    int ti = heap[s].idx;
    heap[s].idx = heap[p].idx;
    heap[p].idx = ti;
    pos[heap[s].idx] = s;
    pos[heap[p].idx] = p;
    s = p;
  }
  return s;
}
void Del(int s, int h) {
  heaptop[h][heap[s].rang] = 0;
  int c = heap[s].kid;
  while (c != 0) {
    int nx = heap[c].sib;
    heap[c].par = 0;
    heap[c].sib = 0;
    heaptop[0][heap[c].rang] = c;
    c = nx;
  }
  pos[heap[s].idx] = 0;
  Merge(0, h);
  Upd(h);
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  int q;
  int sizeadd = 0;
  std::cin >> n >> q;
  heap.push_back({0, 0, 0, 0, 0, 0, 0});
  heaptop.resize(n + 1);
  for (int i = 0; i <= n; i++) {
    heaptop[i].resize(cH21);
  }
  mn.resize(n + 1);
  pos.resize(q + 2);
  for (int i = 0; i < q; i++) {
    int k;
    std::cin >> k;
    if (k == 0) {
      int h;
      int x;
      std::cin >> h >> x;
      ++sizeadd;
      heap.push_back({x, 0, 0, 0, sizeadd, 0, 0});
      pos[sizeadd] = sizeadd;
      heaptop[0][0] = sizeadd;
      Merge(0, h);
    } else if (k == 1) {
      int a;
      int b;
      std::cin >> a >> b;
      Merge(a, b);
    } else if (k == 2) {
      int e;
      std::cin >> e;
      if (pos[e] != 0) {
        int s = SiftUp(pos[e], true);
        Del(s, heap[s].nheap);
      }
    } else if (k == 3) {
      int e;
      long long x;
      std::cin >> e >> x;
      if (pos[e] != 0) {
        int s = pos[e];
        if (x <= heap[s].val) {
          heap[s].val = x;
          s = SiftUp(s, false);
          while (heap[s].par != 0) {
            s = heap[s].par;
          }
          Upd(heap[s].nheap);
        } else {
          s = SiftUp(s, true);
          int h = heap[s].nheap;
          Del(s, h);
          heap[s].val = x;
          heap[s].idx = e;
          pos[e] = s;
          heap[s].par = 0;
          heap[s].kid = 0;
          heap[s].sib = 0;
          heap[s].rang = 0;
          heaptop[0][0] = s;
          Merge(0, h);
        }
      }
    } else if (k == 4) {
      int a;
      std::cin >> a;
      std::cout << heap[mn[a]].val << '\n';
    } else {
      int a;
      std::cin >> a;
      Del(mn[a], a);
    }
  }
  return 0;
}
