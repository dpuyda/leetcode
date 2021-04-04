#include <algorithm>
#include <vector>

class Solution {
public:
  int smallestDistancePair(std::vector<int> &v, const size_t k) {
    if (v.empty()) {
      return 0;
    }
    std::sort(v.begin(), v.end());
    auto lo = 0, hi = v.back() - v.front();
    while (lo < hi) {
      const auto mid = (lo + hi) / 2;
      size_t count = 0;
      for (auto l = v.begin(), r = std::next(v.begin()); r != v.end(); ++r) {
        const auto r_value = *r;
        while (r_value - *l > mid) {
          ++l;
        }
        count += r - l;
      }
      if (count >= k) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }
    return lo;
  }
};

int main() {
  std::vector<int> nums{1, 6, 1};
  Solution solution;
  auto result = solution.smallestDistancePair(nums, 3);
  return 0;
}
