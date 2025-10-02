#include <iostream>
#include <vector>

class Fibonacci {
public:
    // Method to generate Fibonacci series up to 'n' terms
    std::vector<int> generate(int n) {
        std::vector<int> fibonacciSeries;

        // Base cases
        if (n >= 1) fibonacciSeries.push_back(0); // F(0) = 0
        if (n >= 2) fibonacciSeries.push_back(1); // F(1) = 1

        // Generate the series
        for (int i = 2; i < n; ++i) {
            int nextTerm = fibonacciSeries[i - 1] + fibonacciSeries[i - 2];
            fibonacciSeries.push_back(nextTerm);
        }

        return fibonacciSeries; // Return the full series
    }
};

int main() {
    Fibonacci fib;
    int n;

    std::cout << "Enter the number of terms for the Fibonacci series: ";
    std::cin >> n;

    std::vector<int> result = fib.generate(n);

    std::cout << "Fibonacci Series up to " << n << " terms: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
