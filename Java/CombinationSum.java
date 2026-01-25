// this was the most common and highlt asked problem on FAANG Interviews from Leetcode
// Approach - BackTracking 

class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {

        List<Integer> active = new ArrayList<>();
        List<List<Integer>> ans = new ArrayList<>();
        helper(0, target, candidates, active, ans);
        return ans;
    }
    static void helper (int index, int target, int[] candidates, List<Integer> active, List<List<Integer>> ans) {

        if (target == 0) {
            ans.add(new ArrayList<>(active));
            return;
        }

        if (index == candidates.length) {
            return;
        }

        if (candidates[index] <= target) {
            active.add(candidates[index]);
            helper (index, target - candidates[index], candidates, active, ans);
            active.remove(active.size() - 1);
        }
        helper (index + 1, target, candidates, active, ans);
    }
}
