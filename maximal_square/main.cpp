#include <algorithm>
#include <vector>

class Solution {
public:
  int maximalSquare(std::vector<std::vector<char>> &matrix) {
    if (matrix.empty()) {
      return 0;
    }
    const auto cols = matrix[0].size() + 1u;
    std::vector<int> sizes(cols);
    auto size = 0;
    for (const auto &row : matrix) {
      auto prev = sizes[0];
      for (auto i = 1u; i < cols; ++i) {
        const auto t = sizes[i];
        if (row[i - 1] == '1') {
          sizes[i] = 1 + std::min(prev, std::min(sizes[i - 1], sizes[i]));
          size = std::max(size, sizes[i]);
        } else {
          sizes[i] = 0;
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
