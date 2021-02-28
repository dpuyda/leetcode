#include <numeric>
#include <unordered_map>
#include <vector>

class Solution {
public:
  int maxPoints(std::vector<std::vector<int>> &points) {
    // Maps a slope to the number of points
    std::unordered_map<std::pair<int, int>, int, SlopeHash> map;
    auto result = 0;
    for (auto p = points.begin(); p != points.end(); ++p) {
      map.clear();
      auto vertical_count = 0;
      auto horizontal_count = 0;
      auto duplicates_count = 1;
      auto max_count = 0;
      for (auto q = std::next(p); q != points.end(); ++q) {
        const auto dx = (*q)[0] - (*p)[0];
        const auto dy = (*q)[1] - (*p)[1];
        const auto prod = dx * dy;
        if (prod) {
          const auto gcd = std::gcd(dx, dy);
          const auto sign = (prod > 0) - (prod < 0);
          const auto enumerator = sign * std::abs(dx) / gcd;
          const auto denominator = std::abs(dy) / gcd;
          auto [it, success] =
              map.try_emplace(std::make_pair(enumerator, denominator), 1);
          if (!success) {
            ++it->second;
          }
          max_count = std::max(max_count, it->second);
        } else if (dx == 0 && dy == 0) {
          ++duplicates_count;
        } else if (dx == 0) {
          max_count = std::max(max_count, ++vertical_count);
        } else {
          max_count = std::max(max_count, ++horizontal_count);
        }
      }
      result = std::max(result, max_count + duplicates_count);
    }
    return result;
  }

private:
  struct SlopeHash {
    std::size_t operator()(const std::pair<int, int> &pair) const {
      return std::hash<int>()(pair.first) ^ std::hash<int>()(pair.second);
    }
  };
};

int main() {
  std::vector<std::vector<int>> points;
  points.push_back({1, 1});
  points.push_back({3, 2});
  points.push_back({5, 3});
  points.push_back({4, 1});
  points.push_back({2, 3});
  points.push_back({1, 4});
  Solution solution;
  const auto result = solution.maxPoints(points);
  return 0;
}
