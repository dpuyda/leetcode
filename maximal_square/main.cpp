#include <algorithm>
#include <vector>

class Solution {
public:
  int maximalSquare(std::vector<std::vector<char>> &matrix) {
    if (matrix.empty()) {
      return 0;
    }
    const auto rows = matrix.size();
    const auto cols = matrix[0].size() + 1u;
    std::vector<int> sizes(cols);
    auto size = 0;
    for (auto row = 0u; row < rows; ++row) {
      auto prev = sizes[0];
      for (auto col = 1u; col < cols; ++col) {
        const auto t = sizes[col];
        if (matrix[row][col - 1] == '1') {
          sizes[col] = 1 + std::min(sizes[col - 1], std::min(prev, sizes[col]));
          size = std::max(size, sizes[col]);
        } else {
          sizes[col] = 0;
        }
        prev = t;
      }
    }
    return size * size;
  }
};

int main() {
  std::vector<std::vector<char>> matrix;
  matrix.push_back({'0', '1'});
  matrix.push_back({'1', '0'});
  Solution solution;
  auto result = solution.maximalSquare(matrix);
  return 0;
}
