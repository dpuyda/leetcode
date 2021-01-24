#include <algorithm>
#include <unordered_set>
#include <vector>

class Solution {
public:
  int longestConsecutive(std::vector<int> &nums) {
    auto max_length = 0;
    std::unordered_set<int> s(nums.begin(), nums.end());
    for (auto it = s.begin(); it != s.end(); it = s.erase(it)) {
      auto length = 1;
      const auto num = *it;
      for (auto i = num + 1; s.erase(i); ++i) {
        ++length;
      }
      for (auto i = num - 1; s.erase(i); --i) {
        ++length;
      }
      max_length = std::max(max_length, length);
    }
    return max_length;
  }
};

int main() {
  std::vector<int> nums{1, 2, 0, 1};
  Solution solution;
  auto result = solution.longestConsecutive(nums);
  return 0;
}
