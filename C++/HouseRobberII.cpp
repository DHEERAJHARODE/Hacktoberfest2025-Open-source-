class Solution {
public:
    int robLinear(vector<int>& nums) {
        int prev1 = 0, prev2 = 0;
        for (int num : nums) {
            int temp = max(prev1, prev2 + num);
            prev2 = prev1;
            prev1 = temp;
        }
        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        vector<int> excludeFirst(nums.begin() + 1, nums.end());
        vector<int> excludeLast(nums.begin(), nums.end() - 1);

        return max(robLinear(excludeFirst), robLinear(excludeLast));
    }
};
