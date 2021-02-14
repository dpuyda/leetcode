#include <unordered_map>
#include <vector>

class Solution {
public:
  int numSubmatrixSumTarget(std::vector<std::vector<int>> &matrix,
                            const int target) {
    if (matrix.empty()) {
      return 0;
    }
    const auto rows = matrix.size(), cols = matrix[0].size();
    std::vector<int> sums(cols, 0);
    auto result = 0;
    for (size_t start_row = 0; start_row < rows; ++start_row) {
      sums = matrix[start_row];
      for (auto end_row = start_row;;) {
        result += numSubsequenceSumTarget(sums, target);
        if (++end_row == rows) {
          break;
        }
        auto &row = matrix[end_row];
        for (size_t col = 0; col < cols; ++col) {
          sums[col] += row[col];
        }
      }
    }
    return result;
  }

private:
  int numSubsequenceSumTarget(const std::vector<int> &sums, const int target) {
    // Maps a sum to the number of subarrays
    static std::unordered_map<int, int> map;
    map.clear();
    map.emplace(0, 1);
    auto sum = 0, result = 0;
    for (const auto value : sums) {
      sum += value;
      const auto diff_it = map.find(sum - target);
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
  std::vector<std::vector<int>> matrix;
  matrix.push_back({0, 1, 0});
  matrix.push_back({1, 1, 1});
  matrix.push_back({0, 1, 0});
  const auto target = 0;
  Solution solution;
  auto result = solution.numSubmatrixSumTarget(matrix, target);
  return 0;
}
