#include <vector>

class Solution {
public:
  int firstMissingPositive(std::vector<int> &nums) {
    const auto size = static_cast<int>(nums.size() + 1u);
    std::vector<bool> flags(size);
    for (auto num : nums) {
      if (num > 0 && num < size) {
        flags[num] = true;
      }
    }
    for (auto it = flags.begin() + 1, end = flags.end(); it != end; ++it) {
      if (!*it) {
        return static_cast<int>(it - flags.begin());
      }
    }
    return size;
  }
};

int main() {
  std::vector<int> nums{1, 2, 0};
  Solution solution;
  auto result = solution.firstMissingPositive(nums);
  return 0;
}
