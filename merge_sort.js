// Merge Sort Implementation in JavaScript
// Time Complexity: O(n log n)
// Space Complexity: O(n)

/**
 * Merges two sorted arrays into a single sorted array
 * @param {Array} left - Left sorted array
 * @param {Array} right - Right sorted array
 * @returns {Array} - Merged sorted array
 */
function merge(left, right) {
    let result = [];
    let leftIndex = 0;
    let rightIndex = 0;

    // Compare elements from both arrays and merge them in sorted order
    while (leftIndex < left.length && rightIndex < right.length) {
        if (left[leftIndex] < right[rightIndex]) {
            result.push(left[leftIndex]);
            leftIndex++;
        } else {
            result.push(right[rightIndex]);
            rightIndex++;
        }
    }

    // Add remaining elements from left array (if any)
    while (leftIndex < left.length) {
        result.push(left[leftIndex]);
        leftIndex++;
    }

    // Add remaining elements from right array (if any)
    while (rightIndex < right.length) {
        result.push(right[rightIndex]);
        rightIndex++;
    }

    return result;
}

/**
 * Recursively divides array into smaller subarrays and merges them back in sorted order
 * @param {Array} array - Input array to be sorted
 * @returns {Array} - Sorted array
 */
function mergeSort(array) {
    // Base case: arrays of length 0 or 1 are already sorted
    if (array.length <= 1) {
        return array;
    }

    // Find the middle point to divide array into two halves
    const middle = Math.floor(array.length / 2);

    // Divide array into left and right halves
    const left = array.slice(0, middle);
    const right = array.slice(middle);

    // Recursively sort both halves and merge them
    return merge(mergeSort(left), mergeSort(right));
}

// Test the implementation
function main() {
    // Test case 1: Random array
    const arr1 = [64, 34, 25, 12, 22, 11, 90];
    console.log("Original array 1:", arr1);
    console.log("Sorted array 1:", mergeSort([...arr1]));

    // Test case 2: Already sorted array
    const arr2 = [1, 2, 3, 4, 5];
    console.log("\nOriginal array 2:", arr2);
    console.log("Sorted array 2:", mergeSort([...arr2]));

    // Test case 3: Reverse sorted array
    const arr3 = [5, 4, 3, 2, 1];
    console.log("\nOriginal array 3:", arr3);
    console.log("Sorted array 3:", mergeSort([...arr3]));

    // Test case 4: Array with duplicates
    const arr4 = [3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5];
    console.log("\nOriginal array 4:", arr4);
    console.log("Sorted array 4:", mergeSort([...arr4]));
}

// Run the test cases
main();