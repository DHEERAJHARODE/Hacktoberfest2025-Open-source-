class Solution {
    public int removeDuplicates(int[] nums) {
        int n = nums.length, j = 1, ans = 0;
        for (int i = 0; i < n; i++) {
            while (i + 1 < n && nums[i] == nums[i + 1]) {
                i++;
            }
            if (i + 1 < n)
                nums[j++] = nums[i + 1];
            ans++;
        }
        return ans;
    }
}
