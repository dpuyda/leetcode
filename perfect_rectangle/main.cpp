#include <set>
#include <vector>

class Solution {
public:
  bool isRectangleCover(std::vector<std::vector<int>> &rectangles) {
    auto area = 0;
    std::set<std::pair<int, int>> corners;

    const auto insert = [&](int x, int y) {
      const auto [it, inserted] = corners.emplace(x, y);
      if (!inserted) {
        corners.erase(it);
      }
    };

    for (const auto &rect : rectangles) {
      insert(rect[0], rect[1]);
      insert(rect[0], rect[3]);
      insert(rect[2], rect[1]);
      insert(rect[2], rect[3]);
      area += (rect[2] - rect[0]) * (rect[3] - rect[1]);
    }

    return corners.size() == 4 &&
           area == ((*corners.rbegin()).first - (*corners.begin()).first) *
                       ((*corners.rbegin()).second - (*corners.begin()).second);
  }
};

int main() {
  std::vector<std::vector<int>> rectangles;
  rectangles.push_back({1, 1, 3, 3});
  rectangles.push_back({3, 1, 4, 2});
  rectangles.push_back({3, 2, 4, 4});
  rectangles.push_back({1, 3, 2, 4});
  rectangles.push_back({2, 3, 3, 4});
  Solution solution;
  auto result = solution.isRectangleCover(rectangles);
  return 0;
}
