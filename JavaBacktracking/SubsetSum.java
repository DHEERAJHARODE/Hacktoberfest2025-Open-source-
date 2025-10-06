// Problem: Subset Sum / Power Set
// Description: Generate all possible subsets of a given set of numbers using backtracking.

import java.util.ArrayList;

class SubsetSum {
    static void printSubsets(ArrayList<Integer> subset) {
        System.out.println(subset);
    }

    static void generateSubsets(int arr[], ArrayList<Integer> subset, int index) {
        if (index == arr.length) {
            printSubsets(subset);
            return;
        }

        // Include current element
        subset.add(arr[index]);
        generateSubsets(arr, subset, index + 1);

        // Exclude current element (backtrack)
        subset.remove(subset.size() - 1);
        generateSubsets(arr, subset, index + 1);
    }

    public static void main(String args[]) {
        int arr[] = {1, 2, 3};
        ArrayList<Integer> subset = new ArrayList<>();
        generateSubsets(arr, subset, 0);
    }
}
