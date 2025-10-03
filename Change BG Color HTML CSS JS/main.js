const button = document.querySelector('button');
const h2El = document.querySelector('h2');
const bgEl = document.querySelector('section');

// Membuat transisi yang halus untuk perubahan background color
bgEl.style.transition = "background-color 0.5s ease";

// Menambahkan event listener untuk menyalin teks hex ketika h2 diklik
h2El.addEventListener('click', () => {
  const colorCode = h2El.innerText;
  navigator.clipboard.writeText(colorCode).then(() => {
    alert(`Copied ${colorCode} to clipboard!`);
  }).catch(err => {
    console.error('Failed to copy: ', err);
  });
});

button.addEventListener('click', () => {
  let color = '#';
  
  // Menghasilkan warna hex random
  color += Math.random().toString(16).slice(2, 8).toUpperCase();

  // Memastikan warna hex selalu 6 karakter
  while (color.length < 7) {
    color += '0';
  }

  // Menerapkan warna dan mengubah teks h2
  bgEl.style.backgroundColor = color;
  h2El.innerText = color;
});
