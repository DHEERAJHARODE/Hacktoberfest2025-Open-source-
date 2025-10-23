#include <stdio.h>

// Function to calculate binomial coefficient C(n, k)
// Time Complexity: O(k)
unsigned long long binomial_coefficient(int n, int k) {
    unsigned long long result = 1;

    // Since C(n, k) = C(n, n-k), we choose the smaller value for k
    if (k > n - k) {
        k = n - k;
    }

    // Calculate [n * (n-1) * ... * (n-k+1)] / [k * (k-1) * ... * 1]
    for (int i = 0; i < k; i++) {
        result *= (n - i);
        result /= (i + 1);
    }

    return result;
}

// Function to calculate the n-th Catalan number
// C_n = (1/(n+1)) * (2n choose n)
// Time Complexity: O(n)
unsigned long long catalan(int n) {
    if (n < 0) return 0;
    // Calculate value of (2n choose n)
    unsigned long long c = binomial_coefficient(2 * n, n);
    // Return C_n
    return c / (n + 1);
}

int main() {
    int n;
    printf("Enter the number (0-34): ");
    scanf("%d", &n);

    if (n < 0 || n > 34) {
        printf("\nInput out of range for unsigned long long.\n");
        return 1;
    }

    printf("\nRequired Catalan Number = %llu.\n", catalan(n));

    printf("\nCatalan Series formed: ");
    for (int i = 0; i <= n; i++) {
        printf("%llu ", catalan(i));
    }
    printf("\n");

    return 0;
}
