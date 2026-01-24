function debounce(fn, delay) {
  let timeoutId;
  return function (...args) {
    if (timeoutId) {
      clearTimeout(timeoutId);
    }
    timeoutId = setTimeout(() => fn.apply(this, args), delay);
  };
}

// Example usage: Debouncing window resize
window.addEventListener(
  'resize',
  debounce(() => {
    console.log('Resized!');
  }, 300)
);
