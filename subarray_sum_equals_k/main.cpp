#include <unordered_map>
#include <vector>

class Solution {
public:
  int subarraySum(const std::vector<int> &nums, const int k) {
    // Maps a sum to the number of subarrays
    std::unordered_map<int, int> map;
    map.clear();
    map.emplace(0, 1);
    auto sum = 0, result = 0;
    for (const auto value : nums) {
      sum += value;
      const auto diff_it = map.find(sum - k);
      if (diff_it != map.end()) {
        result += diff_it->second;
      }
      auto [sum_it, success] = map.try_emplace(sum, 1);
      if (!success) {
        ++sum_it->second;
      }
    }
    return result;
  }
};

int main() {
  std::vector<int> nums{1, 1, 1};
  Solution solution;
  auto result = solution.subarraySum(nums, 2);
  return 0;
}
