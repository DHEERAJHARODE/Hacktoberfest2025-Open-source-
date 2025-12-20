// Problem Statement
// You have n jobs, where each job is represented by startTime[i], endTime[i], and profit[i]. 
// You're given three arrays startTime, endTime, and profit of the same length n, where startTime[i] 
// is the start time of the ith job, endTime[i] is the end time of the ith job, and profit[i] is the 
// profit of the ith job.

// You want to maximize your profit by choosing a subset of non-overlapping jobs to complete. 
// Return the maximum profit you can achieve.

import java.util.*;

class Job {
    int start, end, profit;

    Job(int start, int end, int profit) {
        this.start = start;
        this.end = end;
        this.profit = profit;
    }
}

public class MaxProfitJobScheduling {
    public static int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        int n = startTime.length;
        Job[] jobs = new Job[n];
        for (int i = 0; i < n; i++) {
            jobs[i] = new Job(startTime[i], endTime[i], profit[i]);
        }
        
        Arrays.sort(jobs, (a, b) -> a.end - b.end);

        int[] dp = new int[n];
        dp[0] = jobs[0].profit;

        for (int i = 1; i < n; i++) {
            int includeProfit = jobs[i].profit;
            int l = binarySearch(jobs, i);
            if (l != -1) {
                includeProfit += dp[l];
            }
            dp[i] = Math.max(dp[i - 1], includeProfit);
        }

        return dp[n - 1];
    }

    private static int binarySearch(Job[] jobs, int index) {
        int lo = 0, hi = index - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (jobs[mid].end <= jobs[index].start) {
                if (jobs[mid + 1].end <= jobs[index].start) {
                    lo = mid + 1;
                } else {
                    return mid;
                }
            } else {
                hi = mid - 1;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] startTime = {1, 2, 3, 4, 6};
        int[] endTime = {3, 5, 10, 6, 9};
        int[] profit = {20, 20, 100, 70, 60};
        
        System.out.println("Maximum Profit: " + jobScheduling(startTime, endTime, profit));
    }
}



// Explanation
// Job Class:

// A Job class is created to store the start time, end time, and profit of each job.
// Sort Jobs by End Time:

// Sort the jobs array by the end times of the jobs to facilitate the binary search.
// Dynamic Programming Array:

// Use a dp array where dp[i] represents the maximum profit up to the ith job.
// Initialize dp[0] with the profit of the first job.
// Binary Search:

// For each job, use binary search to find the last job that ends before the current job starts.
// This helps in finding the maximum profit by including the current job without overlapping.
// Calculate Maximum Profit:

// For each job, calculate the maximum profit by either including the current job or excluding it.
// Update the dp array accordingly.
// Output the Result:

// The last element of the dp array will have the maximum profit that can be achieved by scheduling 
// the jobs.