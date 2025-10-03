class Solution {
    trap(height) {
        const n = height.length;

        let ans = 0;
        let left = 0;
        let right = n - 1;
        let lmax = height[left];
        let rmax = height[right];

        while (left < right) {
            if (lmax <= rmax) {
                left++;
                lmax = Math.max(lmax, height[left]);
                ans += lmax - height[left];
            } else {
                right--;
                rmax = Math.max(rmax, height[right]);
                ans += rmax - height[right];
            }
        }
        return ans;
    }
}

// Example usage:
const solution = new Solution();
console.log(solution.trap([0,1,0,2,1,0,1,3,2,1,2,1])); // Output: 6 
