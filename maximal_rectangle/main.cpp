#include <algorithm>
#include <vector>

class Solution {
public:
  int maximalRectangle(std::vector<std::vector<char>> &matrix) {
    if (matrix.empty()) {
      return 0;
    }
    const auto cols = matrix[0].size();
    std::vector<int> sums(cols);
    auto area = 0;
    for (const auto &row : matrix) {
      for (size_t i = 0u; i < cols; ++i) {
        sums[i] = (row[i] == '1') * (sums[i] + 1);
      }
      area = std::max(area, largestRectangleInHistogram(sums));
    }
    return area;
  }

private:
  int largestRectangleInHistogram(std::vector<int> &heights) {
    size_t area = 0u;
    heights.push_back(0);
    const auto size = heights.size();
    std::vector<size_t> stack;
    stack.push_back(-1);
    for (size_t right = 0u; right < size;) {
      if (stack.size() == 1u || heights[right] >= heights[stack.back()]) {
        stack.push_back(right++);
      } else {
        const auto left = stack.back();
        stack.pop_back();
        area = std::max(area, heights[left] * (right - stack.back() - 1));
      }
    }
    return area;
  }
};

int main() {
  std::vector<std::vector<char>> matrix;
  matrix.push_back({'1', '0'});
  matrix.push_back({'0', '1'});
  Solution solution;
  auto result = solution.maximalRectangle(matrix);
  return 0;
}
