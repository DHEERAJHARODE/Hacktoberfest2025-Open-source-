function isPalindrome(str) {
  // Remove non-alphanumeric characters and convert to lowercase
  const sanitized = str.toLowerCase().replace(/[^a-z0-9]/g, '');
  
  // Use two-pointer technique to compare the string from both ends
  let left = 0;
  let right = sanitized.length - 1;

  while (left < right) {
    if (sanitized[left] !== sanitized[right]) {
      return false; // If mismatch found, exit early
    }
    left++;
    right--;
  }
  return true;
}

// Example usage
console.log(isPalindrome("A man, a plan, a canal: Panama")); // true
console.log(isPalindrome("hello")); // false
