#include <iostream>
#include <string>
#include <vector>
std::vector<int> pos;
std::vector<std::pair<long long, long long>> arr;
void SiftUp(int curpos) {
  while (curpos > 1 && arr[curpos / 2].first > arr[curpos].first) {
    int y = pos[arr[curpos].second];
    pos[arr[curpos].second] = pos[arr[curpos / 2].second];
    pos[arr[curpos / 2].second] = y;
    std::pair<long long, long long> u = arr[curpos];
    arr[curpos] = arr[curpos / 2];
    arr[curpos / 2] = u;
    curpos /= 2;
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int q;
  std::cin >> q;
  arr.push_back({0, 0});
  for (int i = 0; i < q; i++) {
    std::string k;
    std::cin >> k;
    if (k == "decreaseKey") {
      pos.push_back(0);
      int z;
      int d;
      std::cin >> z >> d;
      arr[pos[z - 1]].first -= d;
      SiftUp(pos[z - 1]);
    } else if (k == "insert") {
      int x;
      std::cin >> x;
      pos.push_back(arr.size());
      arr.push_back({x, i});
      SiftUp(arr.size() - 1);
    } else if (k == "getMin") {
      pos.push_back(0);
      std::cout << arr[1].first << '\n';
    } else {
      pos.push_back(0);
      int y = pos[arr[1].second];
      pos[arr[1].second] = pos[arr[arr.size() - 1].second];
      pos[arr[arr.size() - 1].second] = y;
      std::pair<long long, long long> u = arr[1];
      arr[1] = arr[arr.size() - 1];
      arr[arr.size() - 1] = u;
      arr.pop_back();
      int curpos = 1;
      while (
          (curpos * 2 < (int)arr.size() &&
           arr[curpos * 2].first < arr[curpos].first) ||
          (curpos * 2 + 1 < (int)arr.size() &&
           arr[curpos * 2 + 1].first < arr[curpos].first)) {
        int y = pos[arr[curpos].second];
        std::pair<long long, long long> u = arr[curpos];
        if ((arr[curpos * 2].first < arr[curpos].first) &&
            (curpos * 2 + 1 >= (int)arr.size() ||
             arr[curpos * 2 + 1].first >= arr[curpos * 2].first)) {
          pos[arr[curpos].second] = pos[arr[curpos * 2].second];
          pos[arr[curpos * 2].second] = y;
          arr[curpos] = arr[curpos * 2];
          arr[curpos * 2] = u;
          curpos *= 2;
        } else {
          pos[arr[curpos].second] = pos[arr[curpos * 2 + 1].second];
          pos[arr[curpos * 2 + 1].second] = y;
          arr[curpos] = arr[curpos * 2 + 1];
          arr[curpos * 2 + 1] = u;
          curpos = curpos * 2 + 1;
        }
      }
    }
  }
  return 0;
}
