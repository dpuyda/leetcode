#include <vector>

class Solution {
public:
  int largestRectangleArea(std::vector<int> &heights) {
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
  std::vector<int> heights{4, 2, 0, 3, 2, 5};
  Solution solution;
  auto result = solution.largestRectangleArea(heights);
  return 0;
}
