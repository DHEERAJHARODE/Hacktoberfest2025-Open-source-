const fibonacci = (function () {
  const memo = {};

  function f(n) {
    if (n <= 1) return n;

    if (memo[n]) return memo[n];

    const result = f(n - 1) + f(n - 2);
    memo[n] = result; // Cache the result for future calls
    return result;
  }

  return f;
})();

// Example usage
console.log(fibonacci(10)); // 55
console.log(fibonacci(50)); // 12586269025
