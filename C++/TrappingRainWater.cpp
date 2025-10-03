class Solution {
public:
    int trap(std::vector<int>& height) {
        int i = 0, left_max = height[0], sum = 0;
        int j = height.size() - 1, right_max = height[j];
        while (i < j) {
            if (left_max <= right_max) {
                sum += (left_max - height[i]);
                i++;
                left_max =max(left_max, height[i]);
            } else {
                sum += (right_max - height[j]);
                j--;
                right_max =max(right_max, height[j]);
            }
        }
        return sum;
    }
};
